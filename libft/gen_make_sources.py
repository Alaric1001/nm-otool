import argparse
import glob
import os
import subprocess

SOURCES_CONTENT = \
"""## Auto generated make tool, don't edit manually.

OBJ_FILES_{0} := {1}
OBJECTS{2} += $(patsubst %, {0}/$(OBJECT_DIR)/%, $(OBJ_FILES_{0}))"""

RULES_CONTENT = \
"""## Auto generated make tool, don't edit manually.
{0}/$(OBJECT_DIR)/%.o: {0}/%.c
	$(COMP) $@ $<
{1}"""

arg_parser = argparse.ArgumentParser(description='Generate Makefile utility files')
arg_parser.add_argument('-e', '--exec', help='Specify the exec_file')
arg_parser.add_argument('directories', metavar='Dir', nargs='+',
                    help='Directories containing sources files')
args = arg_parser.parse_args()

def format_c_file(file, padding):
    file = ' ' * padding + os.path.basename(file)
    return file.replace('.c', '.o \\')

def get_file_dependencies(dir, file):
    obj = dir + '/$(OBJECT_DIR)/'+ os.path.basename(file).replace('.c', '.o')
    return subprocess.run(['clang', '-MT', obj, '-MM', '-MP', '-I.', file], stdout=subprocess.PIPE).stdout

def remove_dup_lines(str):
    ret = subprocess.run(['awk', 'NF && (!/:$/ || !seen[$0]++)'], stdout=subprocess.PIPE, input=str).stdout
    return ret.decode('utf-8')

def write_sources(dir, objects, args):
    sources = open(os.path.join(dir, 'Sources.mk'), 'w')
    if args.exec:
        sources.write(SOURCES_CONTENT.format(dir, objects, '_' + args.exec.upper()))
    else:
        sources.write(SOURCES_CONTENT.format(dir, objects, ''))
    sources.close()

def write_rules(dir, deps):
    deps_file = open(os.path.join(dir, 'Rules.mk'), 'w')
    deps_file.write(RULES_CONTENT.format(dir, remove_dup_lines(deps)))
    deps_file.close()

for dir in args.directories:
    objects = None
    deps = None
    for file in glob.glob(os.path.join(dir, '*.c')):
        if objects is None:
            objects = format_c_file(file, 0) + '\n'
            deps = get_file_dependencies(dir, file)
        else:
            objects += format_c_file(file, len('OBJ_FILES_' +  dir + ' := ')) + '\n'
            deps += get_file_dependencies(dir, file)
    if objects is None:
        objects = ''
    if deps is None:
        deps = b''
    objects = objects[:len(objects) - 3] + '\n'
    write_sources(dir, objects, args)
    write_rules(dir, deps)

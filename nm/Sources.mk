## Auto generated make tool, don't edit manually.

OBJ_FILES_nm := add_to_obuff.o \
                display_symbols.o \
                get_symbols.o \
                nm.o \
                nm_options.o \
                sort_symbols.o

OBJECTS_NM += $(patsubst %, nm/$(OBJECT_DIR)/%, $(OBJ_FILES_nm))
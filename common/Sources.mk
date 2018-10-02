## Auto generated make tool, don't edit manually.

OBJ_FILES_common := display_sections.o \
                    file_utils.o \
                    get_file_type.o \
                    get_sections.o \
                    get_struct_size.o \
                    mmap_utils.o \
                    safe_access.o

OBJECTS += $(patsubst %, common/$(OBJECT_DIR)/%, $(OBJ_FILES_common))
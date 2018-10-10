## Auto generated make tool, don't edit manually.

OBJ_FILES_common := file_utils.o \
                    get_file_type.o \
                    get_sections.o \
                    get_struct_size.o \
                    get_utils.o \
                    mmap_utils.o \
                    safe_access.o \
                    split_arch.o \
                    split_fat.o

OBJECTS += $(patsubst %, common/$(OBJECT_DIR)/%, $(OBJ_FILES_common))
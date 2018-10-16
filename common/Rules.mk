## Auto generated make tool, don't edit manually.
common/$(OBJECT_DIR)/%.o: common/%.c
	$(COMP) $@ $<
common/$(OBJECT_DIR)/display_title.o: common/display_title.c \
  common/common.h common/data_structures.h common/typedefs.h \
  libft/memory/memory.h common/opt/opt.h libft/output/obuff.h
common/common.h:
common/data_structures.h:
common/typedefs.h:
libft/memory/memory.h:
common/opt/opt.h:
libft/output/obuff.h:
common/$(OBJECT_DIR)/file_utils.o: common/file_utils.c common/common.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  common/opt/opt.h libft/output/output.h
libft/output/output.h:
common/$(OBJECT_DIR)/get_file_type.o: common/get_file_type.c \
  common/common.h common/data_structures.h common/typedefs.h \
  libft/memory/memory.h common/opt/opt.h
common/$(OBJECT_DIR)/get_sections.o: common/get_sections.c \
  common/common.h common/data_structures.h common/typedefs.h \
  libft/memory/memory.h common/opt/opt.h
common/$(OBJECT_DIR)/get_struct_size.o: common/get_struct_size.c \
  common/common.h common/data_structures.h common/typedefs.h \
  libft/memory/memory.h common/opt/opt.h
common/$(OBJECT_DIR)/get_utils.o: common/get_utils.c common/common.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  common/opt/opt.h
common/$(OBJECT_DIR)/has_different_cpu.o: common/has_different_cpu.c \
  common/common.h common/data_structures.h common/typedefs.h \
  libft/memory/memory.h common/opt/opt.h
common/$(OBJECT_DIR)/mmap_utils.o: common/mmap_utils.c common/common.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  common/opt/opt.h libft/output/output.h
common/$(OBJECT_DIR)/parse_macho.o: common/parse_macho.c common/common.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  common/opt/opt.h
common/$(OBJECT_DIR)/safe_access.o: common/safe_access.c common/common.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  common/opt/opt.h
common/$(OBJECT_DIR)/split_arch.o: common/split_arch.c common/common.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  common/opt/opt.h libft/string/string.h libft/lists/lists.h
libft/string/string.h:
libft/lists/lists.h:
common/$(OBJECT_DIR)/split_fat.o: common/split_fat.c common/common.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  common/opt/opt.h

## Auto generated make tool, don't edit manually.
utils/$(OBJECT_DIR)/%.o: utils/%.c
	$(COMP) $@ $<
utils/$(OBJECT_DIR)/file_utils.o: utils/file_utils.c utils/utils.h \
  utils/data_structures.h utils/typedefs.h libft/memory/memory.h \
  libft/output/output.h
utils/utils.h:
utils/data_structures.h:
utils/typedefs.h:
libft/memory/memory.h:
libft/output/output.h:
utils/$(OBJECT_DIR)/get_file_type.o: utils/get_file_type.c utils/utils.h \
  utils/data_structures.h utils/typedefs.h libft/memory/memory.h
utils/$(OBJECT_DIR)/get_struct_size.o: utils/get_struct_size.c \
  utils/utils.h utils/data_structures.h utils/typedefs.h
utils/$(OBJECT_DIR)/mmap_utils.o: utils/mmap_utils.c utils/utils.h \
  utils/data_structures.h utils/typedefs.h libft/output/output.h
utils/$(OBJECT_DIR)/safe_access.o: utils/safe_access.c utils/utils.h \
  utils/data_structures.h utils/typedefs.h

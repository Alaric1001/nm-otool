## Auto generated make tool, don't edit manually.
utils/$(OBJECT_DIR)/%.o: utils/%.c
	$(COMP) $@ $<
utils/$(OBJECT_DIR)/file_utils.o: utils/file_utils.c utils/utils.h \
  utils/data_structures.h libft/memory/memory.h libft/output/output.h
utils/utils.h:
utils/data_structures.h:
libft/memory/memory.h:
libft/output/output.h:
utils/$(OBJECT_DIR)/mmap_utils.o: utils/mmap_utils.c utils/utils.h \
  utils/data_structures.h libft/output/output.h

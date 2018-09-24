## Auto generated make tool, don't edit manually.
utils/$(OBJECT_DIR)/%.o: utils/%.c
	$(COMP) $@ $<
utils/$(OBJECT_DIR)/file_utils.o: utils/file_utils.c utils/utils.h \
  libft/memory/memory.h libft/output/obuff.h
utils/utils.h:
libft/memory/memory.h:
libft/output/obuff.h:

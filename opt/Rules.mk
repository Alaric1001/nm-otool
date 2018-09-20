## Auto generated make tool, don't edit manually.
opt/$(OBJECT_DIR)/%.o: opt/%.c
	$(COMP) $@ $<
opt/$(OBJECT_DIR)/opt.o: opt/opt.c opt/opt.h libft/string/string.h \
  libft/memory/memory.h
opt/opt.h:
libft/string/string.h:
libft/memory/memory.h:

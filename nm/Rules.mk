## Auto generated make tool, don't edit manually.
nm/$(OBJECT_DIR)/%.o: nm/%.c
	$(COMP) $@ $<
nm/$(OBJECT_DIR)/nm.o: nm/nm.c utils/utils.h utils/data_structures.h \
  opt/opt.h libft/output/output.h
utils/utils.h:
utils/data_structures.h:
opt/opt.h:
libft/output/output.h:

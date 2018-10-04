## Auto generated make tool, don't edit manually.
nm/$(OBJECT_DIR)/%.o: nm/%.c
	$(COMP) $@ $<
nm/$(OBJECT_DIR)/add_to_obuff.o: nm/add_to_obuff.c nm/nm.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  opt/opt.h libft/output/obuff.h libft/math/math.h libft/string/string.h
nm/nm.h:
common/data_structures.h:
common/typedefs.h:
libft/memory/memory.h:
opt/opt.h:
libft/output/obuff.h:
libft/math/math.h:
libft/string/string.h:
nm/$(OBJECT_DIR)/display_symbols.o: nm/display_symbols.c nm/nm.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  opt/opt.h libft/output/obuff.h common/common.h
common/common.h:
nm/$(OBJECT_DIR)/display_title.o: nm/display_title.c nm/nm.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  opt/opt.h libft/output/obuff.h
nm/$(OBJECT_DIR)/get_symbols.o: nm/get_symbols.c nm/nm.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  opt/opt.h libft/output/obuff.h common/common.h
nm/$(OBJECT_DIR)/nm.o: nm/nm.c nm/nm.h common/data_structures.h \
  common/typedefs.h libft/memory/memory.h opt/opt.h libft/output/obuff.h \
  common/common.h libft/output/output.h
libft/output/output.h:
nm/$(OBJECT_DIR)/sort_symbols.o: nm/sort_symbols.c nm/nm.h \
  common/data_structures.h common/typedefs.h libft/memory/memory.h \
  opt/opt.h libft/output/obuff.h libft/string/string.h

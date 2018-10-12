## Auto generated make tool, don't edit manually.
otool/$(OBJECT_DIR)/%.o: otool/%.c
	$(COMP) $@ $<
otool/$(OBJECT_DIR)/display_section.o: otool/display_section.c \
  otool/otool.h opt/opt.h common/common.h common/data_structures.h \
  common/typedefs.h libft/memory/memory.h libft/string/string.h \
  libft/output/output.h libft/output/obuff.h libft/math/math.h
otool/otool.h:
opt/opt.h:
common/common.h:
common/data_structures.h:
common/typedefs.h:
libft/memory/memory.h:
libft/string/string.h:
libft/output/output.h:
libft/output/obuff.h:
libft/math/math.h:
otool/$(OBJECT_DIR)/otool.o: otool/otool.c otool/otool.h opt/opt.h \
  common/common.h common/data_structures.h common/typedefs.h \
  libft/memory/memory.h libft/output/output.h
otool/$(OBJECT_DIR)/otool_execute.o: otool/otool_execute.c otool/otool.h \
  opt/opt.h common/common.h common/data_structures.h common/typedefs.h \
  libft/memory/memory.h libft/output/output.h
otool/$(OBJECT_DIR)/otool_opt.o: otool/otool_opt.c otool/otool.h \
  opt/opt.h common/common.h common/data_structures.h common/typedefs.h \
  libft/memory/memory.h libft/string/string.h libft/output/output.h

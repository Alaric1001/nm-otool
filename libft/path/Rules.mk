## Auto generated make tool, don't edit manually.
path/$(OBJECT_DIR)/%.o: path/%.c
	$(COMP) $@ $<
path/$(OBJECT_DIR)/ft_pathappend.o: path/ft_pathappend.c path/path.h \
  string/string.h
path/path.h:
string/string.h:
path/$(OBJECT_DIR)/ft_splitfilepath.o: path/ft_splitfilepath.c \
  path/path.h string/string.h memory/memory.h
memory/memory.h:
path/$(OBJECT_DIR)/ft_star_match.o: path/ft_star_match.c path/path.h \
  string/string.h

## Auto generated make tool, don't edit manually.
output/$(OBJECT_DIR)/%.o: output/%.c
	$(COMP) $@ $<
output/$(OBJECT_DIR)/ft_add_char_to_obuff.o: \
  output/ft_add_char_to_obuff.c output/obuff.h
output/obuff.h:
output/$(OBJECT_DIR)/ft_add_int_to_obuff.o: output/ft_add_int_to_obuff.c \
  output/obuff.h
output/$(OBJECT_DIR)/ft_add_nstr_to_obuff.o: \
  output/ft_add_nstr_to_obuff.c output/obuff.h
output/$(OBJECT_DIR)/ft_add_str_to_obuff.o: output/ft_add_str_to_obuff.c \
  output/obuff.h
output/$(OBJECT_DIR)/ft_add_uint_base_to_obuff.o: \
  output/ft_add_uint_base_to_obuff.c output/obuff.h memory/memory.h \
  string/string.h
memory/memory.h:
string/string.h:
output/$(OBJECT_DIR)/ft_add_uint_to_obuff.o: \
  output/ft_add_uint_to_obuff.c output/obuff.h
output/$(OBJECT_DIR)/ft_flush_obuff.o: output/ft_flush_obuff.c \
  output/obuff.h output/output.h memory/memory.h
output/output.h:
output/$(OBJECT_DIR)/ft_putchar.o: output/ft_putchar.c output/output.h
output/$(OBJECT_DIR)/ft_putchar_fd.o: output/ft_putchar_fd.c \
  output/output.h
output/$(OBJECT_DIR)/ft_putcolored.o: output/ft_putcolored.c \
  output/output.h color/color.h
color/color.h:
output/$(OBJECT_DIR)/ft_putendl.o: output/ft_putendl.c output/output.h
output/$(OBJECT_DIR)/ft_putendl_fd.o: output/ft_putendl_fd.c \
  output/output.h
output/$(OBJECT_DIR)/ft_putnbr.o: output/ft_putnbr.c output/output.h
output/$(OBJECT_DIR)/ft_putnbr_fd.o: output/ft_putnbr_fd.c \
  output/output.h
output/$(OBJECT_DIR)/ft_putnbyteswstr.o: output/ft_putnbyteswstr.c \
  output/output.h string/wstring.h
string/wstring.h:
output/$(OBJECT_DIR)/ft_putnchar.o: output/ft_putnchar.c output/output.h
output/$(OBJECT_DIR)/ft_putnstr.o: output/ft_putnstr.c output/output.h
output/$(OBJECT_DIR)/ft_putnstr_fd.o: output/ft_putnstr_fd.c \
  output/output.h string/string.h
output/$(OBJECT_DIR)/ft_putstr.o: output/ft_putstr.c output/output.h \
  string/string.h
output/$(OBJECT_DIR)/ft_putstr_fd.o: output/ft_putstr_fd.c \
  output/output.h string/string.h
output/$(OBJECT_DIR)/ft_putwchar.o: output/ft_putwchar.c output/output.h \
  string/wstring.h
output/$(OBJECT_DIR)/ft_putwchar_fd.o: output/ft_putwchar_fd.c \
  output/output.h string/wstring.h
output/$(OBJECT_DIR)/ft_putwstr.o: output/ft_putwstr.c output/output.h \
  string/wstring.h
output/$(OBJECT_DIR)/ft_putwstr_fd.o: output/ft_putwstr_fd.c \
  output/output.h string/wstring.h

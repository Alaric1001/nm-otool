# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asenat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 17:26:46 by asenat            #+#    #+#              #
#    Updated: 2018/10/16 17:15:25 by asenat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Libft
LIBFT		:= libft/libft.a
MAKELIBFT	:= make -C libft -j5
LIBFT_FLAGS	:= -L./libft -lft
#

## Standard things
#
.SUFFIXES:
NM		:= ft_nm
OTOOL		:= ft_otool
CC 		:= clang
CFLAGS		:= -I. -Wall -Wextra -Werror
LFLAGS		:= $(LIBFT_FLAGS)
RM		:= rm -f
OBJECT_DIR	:= obj
COMP		:= $(CC) $(CFLAGS) -c -o
ifeq ($(shell uname -s), Darwin)
ECHO		:= echo
else
ECHO		:= echo -e
endif
#

## Sources directories
#
TEST_DIRS	:= tests
SRC_DIRS	:= common common/opt nm otool
#

## Colors
#
BLUE		:= "\033[34m"
GREEN		:= "\033[32m"
RED		:= "\033[31m"
RESET		:= "\033[0m"
#

.PHONY: all
all: $(NM) $(OTOOL)

## Including sources files
#
include $(patsubst %, %/Sources.mk, $(SRC_DIRS))
#

OBJ_DIRS	:= $(patsubst %, %/obj, $(SRC_DIRS))

$(NM): $(LIBFT) $(OBJ_DIRS) $(OBJECTS) $(OBJECTS_NM) 
	$(CC) -o $(NM) $(OBJECTS) $(OBJECTS_NM) $(LFLAGS) 
	@$(ECHO) $(BLUE)$(NM)$(GREEN) "linking complete"$(RESET)

$(OTOOL): $(LIBFT) $(OBJ_DIRS) $(OBJECTS) $(OBJECTS_OTOOL) 
	$(CC) -o $(OTOOL) $(OBJECTS) $(OBJECTS_OTOOL) $(LFLAGS)
	@$(ECHO) $(BLUE)$(OTOOL)$(GREEN) "linking complete"$(RESET)

## Including compilation rules
#
include $(patsubst %, %/Rules.mk, $(SRC_DIRS))
#

$(LIBFT):
	@$(MAKELIBFT)

%/$(OBJECT_DIR):
	mkdir $@

## Including tests
#
-include $(patsubst %, %/Rules.mk, $(TEST_DIRS))
include DiffTest.mk
#

.PHONY: clean
clean:
	@$(RM) -r $(OBJ_DIRS)
	@$(ECHO) "Objects directories removed"

.PHONY: fclean
fclean: clean
	@$(RM) $(NM) $(OTOOL) $(TEST_TARGETS)
	@$(MAKELIBFT) fclean
	@$(ECHO) $(NM) "and" $(OTOOL) "deleted"

.PHONY: re
re: fclean all

.PHONY: makedeps
makedeps:
	python3.7 libft/gen_make_sources.py -e nm nm
	python3.7 libft/gen_make_sources.py -e otool otool
	python3.7 libft/gen_make_sources.py common common/opt

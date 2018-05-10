# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaspa <mgaspa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 13:15:45 by mgaspa            #+#    #+#              #
#    Updated: 2018/05/10 16:27:30 by mgaspa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit

SRC_DIR := src
INC_DIR := includes
OBJ_DIR := obj
LIB_DIR := lib
DEP_DIR := dep

SRC := main.c\
	   read.c\
	   solv.c
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
LIB := $(LIB_DIR)/libft.a

CC := gcc
CFLAGS := -Wall -Werror -Wextra
INC = -I$(INC_DIR)

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(patsubst %.c, $(DEP_DIR)/%.d, $(SRC)) $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

$(LIB):
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)
	make clean -C ./lib/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/

re: fclean all

$(DEP_DIR)/%.d: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(DEP_DIR)
	gcc -M -MT $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $<) $(INC) $< > $@
	echo "\t@mkdir -p \$$(OBJ_DIR)" >> $@
	echo "\t\$$(CC) \$$(FLAGS) \$$(INC) -c \$$< -o \$$@" >> $@

include $(patsubst %.c, $(DEP_DIR)/%.d, $(SRC))

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qviguier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 11:53:38 by ddevico           #+#    #+#              #
#    Updated: 2016/03/02 15:15:14 by ddevico          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME	= fdf

CC		= gcc
CFLAGS	= -W -Werror -Wextra -g
LFLAGS	= -lmlx -framework OpenGL -framework AppKit 

SRC_DIR	= ./src
SRC		= fdf.c get_next_line.c ft_readmap.c ft_drawline.c ft_getcolor.c
VPATH	= $(SRC_DIR)

O_DIR	= ./objects
OBJ		= $(addprefix $(O_DIR)/,$(SRC:.c=.o))

LIB_PATH = libraries
LIB_NAME = libftprintf.a
LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@echo LINKING FILLER FROM OBJECTS FILES...
	@echo "Linking binary."
	@$(CC) -o $(NAME) $^ $(LFLAGS) $(LIB)

$(O_DIR)/%.o: %.c
	@echo COMPILING $(@)...
	@mkdir -p $(O_DIR)
	@printf "."
	@$(CC) $(CFLAGS) -c $< -I ./include -o $@

clean:
	@rm -f $(OBJ)
	@echo OBJECTS FILES DELETION COMPLETE !

fclean: clean
	@rm -f $(NAME)
	@echo EXECUTABLE DELETED !

re: fclean all

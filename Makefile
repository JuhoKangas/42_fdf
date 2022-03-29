# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 14:40:43 by jkangas           #+#    #+#              #
#    Updated: 2022/03/29 15:08:54 by jkangas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME := fdf

# Directories
SRC_DIR = ./src
OBJ_DIR := ./obj

# Sourcecs and objects
SRC := main.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Linking
LINKS := -I libft -L libft \
	-I /usr/local/include -L /usr/local/lib \
	-l mlx -l ft -framework OpenGL -framework Appkit

# Commands
RM := /bin/rm -f
RM_DIR := /bin/rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LINKS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJ)
	$(RM_DIR) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all
	$(MAKE) -C libft re
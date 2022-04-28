# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 14:40:43 by jkangas           #+#    #+#              #
#    Updated: 2022/04/28 15:27:31 by jkangas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME := fdf

# Directories
SRC_DIR = ./src
OBJ_DIR := ./obj

# Sourcecs and objects
SRC := main.c error.c map_reader.c map_drawer.c key_controller.c \
		utilities.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -O3

# Linking
LINKS := -I libft -L libft \
	-I /usr/local/include -L /usr/local/lib \
	-l mlx -l ft -framework OpenGL -framework Appkit

# Messages
MSG = \033[0;96m
END = \033[0m

# Commands
RM := /bin/rm -f
RM_DIR := /bin/rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(LINKS) -o $@
	@echo "$(MSG)Done!$(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(MSG)Compiling...$(END)"

clean:
	@$(MAKE) -C libft clean
	@$(RM) $(OBJ)
	@$(RM_DIR) $(OBJ_DIR)
	@echo "$(MSG)Objects removed!$(END)"

fclean: clean
	@$(MAKE) -C libft fclean
	@$(RM) $(NAME)
	@echo "$(MSG)Targets removed!$(END)"


re: fclean all
	@$(MAKE) -C libft re
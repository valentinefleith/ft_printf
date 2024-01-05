# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 17:07:48 by vafleith          #+#    #+#              #
#    Updated: 2024/01/05 15:16:11 by vafleith         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = src
INC_DIR = includes
BUILD_DIR = build
LIBFT = libft

CC = cc
CFLAGS = -Wall -Wextra
CFLAGS += -Werror
CFLAGS += -I$(INC_DIR)

SRCS = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_print_format.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

.PHONY: all
all : $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@echo Building Printf
	@ar rc $(NAME) $(OBJS)
	@echo ft_printf compiled !

$(BUILD_DIR)/%.o : %.c
	@echo Compiling $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo Cleaning up object files
	@rm -rf $(BUILD_DIR)
	@make clean -C $(LIBFT)

.PHONY: fclean
fclean: clean
	@echo Cleaning up printf
	@rm -rf $(NAME)
	@echo Cleaning up libft
	@rm -f $(LIBFT)/libft.a

.PHONY: re
re: fclean all

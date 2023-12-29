# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 17:07:48 by vafleith          #+#    #+#              #
#    Updated: 2023/12/29 17:51:21 by vafleith         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC_DIR = includes
LIBFT = libft
SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c

OBJS = $(SRCS:%.c=%.o)

.PHONY: all
all : $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@echo Building Printf
	@ar rc $(NAME) $(OBJS)
	@echo ft_printf compiled !

%.o : %.c
	@echo Compiling $<
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

.PHONY: clean
clean:
	@echo Cleaning up object files
	@rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	@echo Cleaning up printf
	@rm -rf $(NAME)

.PHONY: re
re: fclean all

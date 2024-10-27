# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtereshc <dtereshc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 20:19:39 by dtereshc          #+#    #+#              #
#    Updated: 2024/11/03 21:12:16 by dtereshc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# vars
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

# src
SRCS = ft_printf.c print_char.c print_hex.c print_int.c print_pointer.c print_string.c print_unsigned.c funcs.c
OBJS = $(SRCS:.c=.o)

# rules 
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)   

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) n

re: fclean all
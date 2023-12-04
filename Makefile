# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 15:26:46 by rsaueia-          #+#    #+#              #
#    Updated: 2023/12/04 19:27:55 by rsaueia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c printf_aux.c

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

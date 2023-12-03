SRC = 

OBJS = $(SRC:.c=.o)

NAME = printf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
            ar -rc $(NAME) $(OBJS)

.c.o:
        $(CC) $(CFLAGS) -c $<

clean:
        rm -f $(OBJS)

fclean: clean
        rm -f $(NAME)

re: fclean all
NAME = libftprintf.a
CC = cc
CFLAG = -Wall -Werror -Wextra

SRC =	ft_printf.c \
		ft_printf_utils.c \
		ft_put_format.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

NAME	=	libftprintf.a

FILES	=	ft_printf.c \
			ft_putchar.c \
			ft_puthex.c\
			ft_putnbr.c \
			ft_putptr.c\
			ft_putstr.c \
			ft_putunbr.c\
			ft_sorting.c

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

OFILES	=	$(FILES:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(FILES)
	ar rc $(NAME) $(OFILES)

all:	$(NAME)

clean:
	rm -f $(OFILES)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
NAME = libftprintf.a

INCLUDES = printf.h

DEFS =	ft_integers.c \
		ft_printf.c \
		ft_string_character.c \
		ft_hex.c \
		ft_pointers.c \
		tools.c

OBJS = $(DEFS:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -Wall -Werror -Wextra -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean all



NAME = libftprintf.a

MSRCS := 	print_characters.c            print_hex.c            print_numbers.c   \
        	print_unsigned_int.c    	ft_printf.c\



MOBJS = $(MSRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

rm = rm -f

all : $(NAME)

%.o :%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(MOBJS)
	ar rcs $(NAME) $(MOBJS)

clean :
	$(rm) $(MOBJS) $(BOBJS)

fclean : clean
	$(rm) $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re

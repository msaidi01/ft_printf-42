NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs

RM = rm -rf

FT_PRINTF_H = ft_printf.h

MANDATORY = ft_putchar.c ft_printf.c ft_puthexa.c ft_strlen.c ft_putstr.c ft_putuns.c ft_putnbr.c

OBJECTS = $(MANDATORY:.c=.o)

$(NAME) :  $(OBJECTS)
			$(AR) $@ $^

%.o : %.c  $(FT_PRINTF_H)
		$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

clean : 
		$(RM) $(OBJECTS)

fclean : clean
		$(RM) $(NAME)

re : fclean all bonus
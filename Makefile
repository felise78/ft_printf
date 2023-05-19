NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRC =	ft_printf.c \
		utils/ft_putchar.c \
		utils/ft_putstr.c \
		utils/ft_putnbr.c \
		utils/ft_putnbr_u.c \
		utils/ft_putnbr_hexa.c \
		utils/ft_ptr.c \

OBJ = $(SRC:.c=.o)

AR = ar rcs #rcs replace create sort

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : 	fclean all

.PHONY: all clean fclean re

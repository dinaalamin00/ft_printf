SRC= check_flag.c ckeck_spec.c digit_count.c flags.c pad.c ft_printf.c \
	 printchar.c printhex.c printnbr.c printptr.c printstr.c printun.c printpercent.c
OBJ = ${SRC.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME= libftprintf.a
OBJ = ${SRC:.c=.o}
LIB = ar rcs


$(NAME) : $(OBJ)
	$(LIB) $(NAME) $(OBJ)

all : $(NAME)

bonus: all

%.o : %.c
	$(CC) $(Cflags) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile for projetcs
##

CC	=	gcc -g3

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include

NAME	=	navy

SRCS	=	srcs/main.c \
		srcs/navy.c \
		srcs/display.c \
		srcs/signal.c \
		srcs/end_game.c \
		srcs/receive_attack.c \
		srcs/send_attack.c \
		srcs/convert.c \
		srcs/error.c \
		srcs/error_input.c \
		srcs/error_map.c \
		srcs/bit_check.c \
		srcs/game.c \
		srcs/parsing.c

OBJS	=	$(SRCS:.c=.o)

LIB =		-L./lib -lmy

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(RM) lib/libmy.a
	make -C ./lib/my fclean


re: fclean all

.PHONY: all clean fclean re

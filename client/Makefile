##
## EPITECH PROJECT, 2022
## MyTeams
## File description:
## Makefile
##

NAME	=	myteams_cli

SRC	=	src/main.c\
		src/client.c\

LIB	=	../libs/circularbuffer/circular_buffer.c\

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

CFLAGS	=	-Wall -Werror -I include/ -I ../libs/myteams -I ../libs/circularbuffer -g

CC	=	gcc

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make

all:	$(NAME)

.PHONY: $(NAME) clean fclean re all

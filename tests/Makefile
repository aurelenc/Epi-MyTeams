##
## EPITECH PROJECT, 2022
## MyFTP
## File description:
## Makefile
##

NAME	=	unit_tests

SERVER_SRC	=	\
				../server/src/server.c\

CLIENT_SRC	=	\
				../client/src/client.c\

LIB_SRC	=	\
			../libs/circularbuffer/circular_buffer.c\

TEST_SRC	=	base_test.c\

CFLAGS	=	-Wall -Werror

LDFLAGS = -lcriterion --coverage -I ../include/

CC	=	gcc

$(NAME):
	$(CC) $(SRC) $(TEST_SRC) -o $(NAME) ${LDFLAGS}

clean:
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)

all:	$(NAME)

.PHONY: $(NAME) clean fclean all

##
## EPITECH PROJECT, 2022
## MyTeams
## File description:
## Makefile
##

NAME	=	myteams_cli

SRC	=	main.c\
		src/client.c\
		src/manage_commands/manage_command.c	\
		src/get_commands/get_cmd_login.c	\
		src/get_commands/get_cmd_logout.c	\
		src/get_commands/check_params.c	\
		src/get_commands/manage_params.c	\
		src/get_commands/get_cmd_send_message.c	\
		src/manage_commands/make_command_rfc_compatible.c	\
		src/manage_commands/parse_server_response.c \
		src/manage_commands/reply_codes.c

LIB	=	../libs/circularbuffer/circular_buffer.c\

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

CFLAGS	=	-Wall -Werror -I ../../../libs/myteams -I ../include -I ../../include -I include/ -I ../libs/myteams -I ../libs/circularbuffer

LDFLAGS	=	 -L ../libs/myteams -lmyteams

CC	=	gcc

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	cp ../libs/myteams/libmyteams.so ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../libmyteams.so

re: fclean
	make

all:	$(NAME)

.PHONY: $(NAME) clean fclean re all

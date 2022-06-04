##
## EPITECH PROJECT, 2022
## MyTeams
## File description:
## Makefile
##

NAME	=	myteams_cli

SRC_COMMANDS	=	src/get_commands/get_cmd_unsubscribe_teams.c	\
					src/get_commands/get_cmd_subscribe_teams.c	\
					src/get_commands/get_cmd_logout.c	\
					src/get_commands/get_cmd_login.c	\
					src/get_commands/get_cmd_send_message.c	\
					src/get_commands/get_cmd_use.c	\
					src/get_commands/get_cmd_create.c	\
					src/get_commands/get_cmd_info.c	\
					src/get_commands/get_cmd_list.c	\
					src/get_commands/get_cmd_messages.c	\
					src/get_commands/get_cmd_user.c	\
					src/get_commands/get_cmd_users.c	\
					src/get_commands/get_cmd_subscribed.c	\
					src/get_commands/get_cmd_help.c



SRC	=	main.c\
		src/client.c\
		src/signals.c\
		src/create_client.c\
		src/manage_commands/manage_command.c	\
		src/get_commands/check_params.c	\
		src/get_commands/print_message.c	\
		src/get_commands/manage_params.c	\
		src/manage_commands/make_command_rfc_compatible.c	\
		src/manage_commands/parse_server_response.c \
		src/manage_commands/reply_codes.c	\
		src/manage_commands/send_command.c	\
		src/manage_commands/utils.c	\

LIB	=	../libs/circularbuffer/circular_buffer.c\

OBJ	=	$(SRC:.c=.o) $(SRC_COMMANDS:.c=.o) $(LIB:.c=.o)

CFLAGS	=	-Wall -Werror -I ../../../libs/myteams -I ../include -I ../../include -I include/ -I ../libs/myteams -I ../libs/circularbuffer -g

LDFLAGS	=	 -L ../libs/myteams -lmyteams

CC	=	gcc

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make

all:	$(NAME)

.PHONY: $(NAME) clean fclean re all

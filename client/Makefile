##
## EPITECH PROJECT, 2022
## MyTeams
## File description:
## Makefile
##

NAME	=	myteams_cli

SRC_COMMANDS	=	src/get_commands/get_cmd_unsubscribe_teams.c	\
					src/get_commands/get_cmd_subscribe_teams.c	\
					src/get_commands/get_cmd_send_message.c	\
					src/get_commands/get_cmd_logout.c	\
					src/get_commands/get_cmd_login.c	\
					src/get_commands/get_use_commands/get_cmd_use_channel.c	\
					src/get_commands/get_use_commands/get_cmd_use_teams.c	\
					src/get_commands/get_use_commands/get_cmd_use_threads.c	\
					src/get_commands/get_info_commands/get_cmd_infos_thread.c	\
					src/get_commands/get_info_commands/get_cmd_infos_team.c	\
					src/get_commands/get_info_commands/get_cmd_infos_channel.c	\
					src/get_commands/get_info_commands/get_cmd_get_user_infos.c	\
					src/get_commands/get_list_commands/get_cmd_list_channels.c	\
					src/get_commands/get_list_commands/get_cmd_list_teams_subscribed.c	\
					src/get_commands/get_list_commands/get_cmd_list_teams.c	\
					src/get_commands/get_list_commands/get_cmd_list_threads.c	\
					src/get_commands/get_list_commands/get_cmd_list_user_subscribed.c	\
					src/get_commands/get_list_commands/get_cmd_list_users_messages.c	\
					src/get_commands/get_list_commands/get_cmd_list_users.c	\
					src/get_commands/get_create_commands/get_cmd_create_channel.c	\
					src/get_commands/get_create_commands/get_cmd_create_teams.c	\
					src/get_commands/get_create_commands/get_cmd_create_thread.c




SRC	=	main.c\
		src/client.c\
		src/manage_commands/manage_command.c	\
		src/get_commands/check_params.c	\
		src/get_commands/manage_params.c	\
		src/manage_commands/make_command_rfc_compatible.c	\
		src/manage_commands/parse_server_response.c \
		src/manage_commands/reply_codes.c

LIB	=	../libs/circularbuffer/circular_buffer.c\

OBJ	=	$(SRC:.c=.o) $(SRC_COMMANDS:.c=.o) $(LIB:.c=.o)

CFLAGS	=	-Wall -Werror -I ../../../libs/myteams -I ../include -I ../../include -I include/ -I ../libs/myteams -I ../libs/circularbuffer

LDFLAGS	=	 -L ../libs/myteams -lmyteams

CC	=	gcc

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make

all:	$(NAME)

.PHONY: $(NAME) clean fclean re all

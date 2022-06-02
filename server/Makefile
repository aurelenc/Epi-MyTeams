##
## EPITECH PROJECT, 2022
## MyTeams
## File description:
## Makefile
##

NAME	=	myteams_server

SRC	=	src/main.c\
		src/server.c\
		src/reply_codes.c\
		src/commands.c\
		src/clients.c\
		src/client_input.c\
		src/cli_launch.c\

COMMANDS_SRC	=	\
					src/commands/login.c\
					src/commands/logout.c\
					src/commands/users.c\
					src/commands/user.c\
					src/commands/send.c\
					src/commands/messages.c\
					src/commands/subscribe.c\
					src/commands/subscribed_teams.c\
					src/commands/subscribed_users.c\
					src/commands/unsubscribe.c\
					src/commands/use_team.c\
					src/commands/use_channel.c\
					src/commands/use_thread.c\
					src/commands/create_team.c\
					src/commands/create_channel.c\
					src/commands/create_thread.c\
					src/commands/create_reply.c\
					src/commands/list_teams.c\
					src/commands/list_channels.c\
					src/commands/list_threads.c\
					src/commands/list_replies.c\
					src/commands/info_team.c\
					src/commands/info_channel.c\
					src/commands/info_thread.c\
					src/commands/info_user.c\

LIB	=	../libs/circularbuffer/circular_buffer.c	\

DATABASE =	../libs/database/tables/channels/channel.c										\
			../libs/database/tables/channels/database_channels_multiple_search.c			\
			../libs/database/tables/channels/database_channels_save.c						\
			../libs/database/tables/channels/channel_search.c								\
			../libs/database/tables/discussions/discussion.c								\
			../libs/database/tables/discussions/discussion_search.c							\
			../libs/database/tables/discussions/database_discussions_save.c					\
			../libs/database/tables/messages/message.c										\
			../libs/database/tables/messages/message_search.c								\
			../libs/database/tables/messages/message_search_relation.c						\
			../libs/database/tables/messages/database_messages_multiple_search_relation.c	\
			../libs/database/tables/messages/database_messages_save.c						\
			../libs/database/tables/teams/team.c											\
			../libs/database/tables/teams/team_search.c										\
			../libs/database/tables/teams/database_teams_save.c								\
			../libs/database/tables/threads/thread.c										\
			../libs/database/tables/threads/database_threads_multiple_search.c				\
			../libs/database/tables/threads/thread_search.c									\
			../libs/database/tables/threads/database_threads_save.c								\
			../libs/database/tables/users/user.c											\
			../libs/database/tables/users/user_search.c										\
			../libs/database/tables/users/database_users_save.c								\
			../libs/database/tables/users_x_teams/database_users_x_teams_multiple_search.c	\
			../libs/database/tables/users_x_teams/user_team_search.c						\
			../libs/database/tables/users_x_teams/users_x_teams.c							\
			../libs/database/tables/users_x_teams/database_users_x_teams_save.c				\
			../libs/database/tables/uuid_gen.c												\
			../libs/database/tables/load_functions.c										\
			../libs/database/database_management.c											\

LIB_LINKED_LIST =	../libs/linked_list/llist_creation.c		\
					../libs/linked_list/llist_destruction.c		\
					../libs/linked_list/llist_access.c			\
					../libs/linked_list/llist_deletion.c		\
					../libs/linked_list/llist_infos.c			\
					../libs/linked_list/llist_insertion.c		\
					../libs/linked_list/llist_tools.c			\

OBJ	=	$(SRC:.c=.o) $(COMMANDS_SRC:.c=.o) $(LIB:.c=.o) $(LIB_LINKED_LIST:.c=.o) $(DATABASE:.c=.o)

CFLAGS	=	-Wall -Werror -I include/ -I ../libs/myteams -I ../libs/circularbuffer -I ../libs/linked_list/ -I ../libs/database

LDFLAGS = -luuid --coverage -I ../libs/linked_list -L../libs/myteams -lmyteams

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

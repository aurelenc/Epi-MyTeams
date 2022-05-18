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

DATABASE =	../libs/database/tables/channel.c			\
			../libs/database/tables/discussion.c		\
			../libs/database/tables/message.c			\
			../libs/database/tables/team.c				\
			../libs/database/tables/thread.c			\
			../libs/database/tables/user.c				\
			../libs/database/search/channel_search.c	\
			../libs/database/search/discussion_search.c	\
			../libs/database/search/message_search.c	\
			../libs/database/search/team_search.c		\
			../libs/database/search/thread_search.c		\
			../libs/database/search/user_search.c		\
			../libs/database/database_init.c			\
			../libs/database/database_destruction.c		\

LIB_LINKED_LIST =	../libs/linked_list/llist_creation.c		\
					../libs/linked_list/llist_destruction.c		\
					../libs/linked_list/llist_access.c			\
					../libs/linked_list/llist_deletion.c		\
					../libs/linked_list/llist_infos.c			\
					../libs/linked_list/llist_insertion.c		\
					../libs/linked_list/llist_tools.c			\

OBJ	=	$(SRC:.c=.o) $(COMMANDS_SRC:.c=.o) $(LIB:.c=.o) $(LIB_LINKED_LIST:.c=.o) $(DATABASE:.c=.o)

CFLAGS	=	-Wall -Werror -I include/ -I ../libs/myteams -I ../libs/circularbuffer -I ../libs/linked_list/ -I ../libs/database -g

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

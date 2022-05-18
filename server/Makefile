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

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o) $(LIB_LINKED_LIST:.c=.o) $(DATABASE:.c=.o) $(COMMANDS_SRC:.c=.o)

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

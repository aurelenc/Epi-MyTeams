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

LIB_LINKED_LIST_SRC =	../libs/linked_list/llist_creation.c		\
						../libs/linked_list/llist_destruction.c		\
						../libs/linked_list/llist_access.c			\
						../libs/linked_list/llist_deletion.c		\
						../libs/linked_list/llist_infos.c			\
						../libs/linked_list/llist_insertion.c		\
						../libs/linked_list/llist_tools.c			\

SAVE_SRC	=	../libs/database/tables/load_functions.c								\
				../libs/database/tables/channels/database_channels_save.c				\
				../libs/database/tables/channels/channel.c								\
				../libs/database/tables/discussions/database_discussions_save.c			\
				../libs/database/tables/discussions/discussion.c						\
				../libs/database/tables/teams/database_teams_save.c						\
				../libs/database/tables/teams/team.c									\
				../libs/database/tables/users/database_users_save.c						\
				../libs/database/tables/users/user.c									\
				../libs/database/tables/users_x_teams/database_users_x_teams_save.c		\
				../libs/database/tables/users_x_teams/users_x_teams.c					\
				../libs/database/database_management.c									\
				../libs/database/tables/uuid_gen.c										\


TEST_LIB_SRC	=	llib/tests_tools.c					\
					llib/tests_llist_init.c				\
					llib/tests_llist_destruction.c		\
					llib/tests_llist_append.c			\
					llib/tests_llist_push_front.c		\
					llib/tests_llist_insert.c			\
					llib/tests_llist_clear.c			\
					llib/tests_llist_pop_back.c			\
					llib/tests_llist_pop_front.c		\
					llib/tests_llist_delete_at.c		\
					llib/tests_llist_get_size.c			\
					llib/tests_llist_dump.c				\
					llib/tests_llist_is_empty.c			\
					llib/tests_llist_multiple_search.c	\
					llib/tests_llist_back.c				\
					llib/tests_llist_front.c			\
					llib/tests_llist_get.c				\
					llib/tests_llist_search.c			\
					llib/tests_llist_take_at_position.c	\
					llib/tests_llist_delif.c			\

TEST_SERV_SAVE_SRC	=	database_save/tests_get_entities.c			\
						database_save/tests_get_arg.c				\
						database_save/tests_get_file_content.c		\
						database_save/tests_save_channels.c			\
						database_save/tests_load_channels.c			\
						database_save/tests_save_discussions.c		\
						database_save/tests_load_discussions.c		\
						database_save/tests_save_teams.c			\
						database_save/tests_load_teams.c			\
						database_save/tests_save_users.c			\
						database_save/tests_load_users.c			\
						database_save/tests_save_users_x_teams.c	\
						database_save/tests_load_users_x_teams.c	\

CFLAGS	=	-Wall -Werror

LDFLAGS = -lcriterion -luuid --coverage -I ../libs/linked_list -I ../server/include -I ../libs/database

CC	=	gcc

$(NAME):
	$(CC) $(LIB_LINKED_LIST_SRC) $(SAVE_SRC) $(TEST_LIB_SRC) $(TEST_SERV_SAVE_SRC) -o $(NAME) ${LDFLAGS}

clean:
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)

all:	$(NAME)

.PHONY: $(NAME) clean fclean all

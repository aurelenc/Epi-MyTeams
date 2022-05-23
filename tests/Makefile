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

TEST_SRC	=	tests_tools.c					\
				tests_llist_init.c				\
				tests_llist_destruction.c		\
				tests_llist_append.c			\
				tests_llist_push_front.c		\
				tests_llist_insert.c			\
				tests_llist_clear.c				\
				tests_llist_pop_back.c			\
				tests_llist_pop_front.c			\
				tests_llist_delete_at.c			\
				tests_llist_get_size.c			\
				tests_llist_dump.c				\
				tests_llist_is_empty.c			\
				tests_llist_back.c				\
				tests_llist_front.c				\
				tests_llist_get.c				\
				tests_llist_search.c			\
				tests_llist_delif.c				\

CFLAGS	=	-Wall -Werror

LDFLAGS = -lcriterion -luuid --coverage -I ../libs/linked_list

CC	=	gcc

$(NAME):
	$(CC) $(LIB_LINKED_LIST_SRC) $(TEST_SRC) -o $(NAME) ${LDFLAGS}

clean:
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)

all:	$(NAME)

.PHONY: $(NAME) clean fclean all

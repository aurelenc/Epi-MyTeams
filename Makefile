##
## EPITECH PROJECT, 2022
## MyFTP
## File description:
## Makefile
##

NAME	=	my_teams
TESTS_NAME	=	unit_tests

CLIENT_NAME	=	myteams_cli
SERVER_NAME	=	myteams_server

$(NAME):
	make -C client
	make -C server
	cp client/$(CLIENT_NAME) .
	cp server/$(SERVER_NAME) .

clean:
	make -C client clean
	make -C server clean
	make -C tests clean

fclean: clean
	make -C client fclean
	make -C server fclean
	make -C tests fclean
	rm -f $(CLIENT_NAME)
	rm -f $(SERVER_NAME)
	rm -f ${TESTS_NAME}

re: fclean
	make

unit_tests: re
	make -C tests
	cp tests/$(TESTS_NAME) .

tests_run: unit_tests
	./$(TESTS_NAME)

all:	$(NAME)

.PHONY: $(NAME) clean fclean re all unit_tests tests_run

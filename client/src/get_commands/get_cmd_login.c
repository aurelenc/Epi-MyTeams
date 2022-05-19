/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_cmd_login
*/

#include <unistd.h>
#include "../../include/get_command.h"

int log_client(char *av, int socket)
{
    char *params;
    char *buff;
    int len_av;

    if (av == NULL)
        return -1;
    params = strdup(av);
    len_av = strlen(av);
    buff = calloc(sizeof(char), (len_av + 7));
    if (buff == NULL)
        exit (84);
    if (check_params(params) == 1) {
        strcat(buff, "LOGI ");
        strcat(buff, av);
        strcat(buff, "\n");
        printf("La command c'est = [%s]\n", buff);
         write(socket, buff, strlen(buff));
    }
    return 0;
}
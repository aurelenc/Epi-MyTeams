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
    char buff[4096];
    int len_av;

    memset(buff, 0, 4096);
    if (av == NULL)
        return -1;
    params = strdup(av);
    len_av = strlen(av);
    //buff = calloc(sizeof(char), (len_av + 7));
    //if (buff == NULL)
    //    exit (84);
    if (check_params(params) == 1) {
        strcat(buff, "LOGI ");
        strcat(buff, av);
        strcat(buff, "\n");
        printf("La command c'est = [%s]\n", buff);
        write(socket, buff, strlen(buff));
        memset(buff, 0, (len_av + 7));
        read(socket, buff, 4096); // 3 = lenth error code
        printf("Response server = [%s]\n", buff);
        // atoi -> compare error code
    }
    return 0;
}
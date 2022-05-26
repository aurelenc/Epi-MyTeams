/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_cmd_login
*/

#include <unistd.h>
#include "get_command.h"

int log_client(char *av, int socket)
{
    char buff[4096];

    memset(buff, 0, 4096);
    if (av == NULL)
        return -1;
    if (check_params(av) == 1) {
        printf("\nArgument av are = [%s]\n", av);
        make_command_rfc_compatible(buff, "LOGIN ", av);
        printf("Response 0 du server = [%s]\n", buff);
        write(socket, buff, strlen(buff));
        printf("Response 1 du server = [%s]\n", buff);
        memset(buff, 0, (strlen(av) + 7));
        printf("Response 2 du server = [%s]\n", buff);
        ///read(socket, buff, 4096); // 3 = lenth error code
        printf("Response 3 du server = [%s]\n", buff);
        // atoi -> compare error code
    } else  {
        printf("Command are not good use /help for more information !\n");
    }
    return 0;
}
/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_cmd_login
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"

int login_client(char *av, int socket)
{
    char **tab_response = NULL;

    if (av == NULL)
        return -1;
    if (check_params(av) == 1) {
        tab_response = send_command(av, tab_response, "LOGI ", socket);
    } else {
        printf("Command are not good use /help for more information !\n");
    }
    return 0;
}

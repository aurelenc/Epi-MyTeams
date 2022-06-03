/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_cmd_send_message
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_command.h"
#include "reply_codes.h"

int send_message(char *av, int socket)
{
    char buff[4096] = {0};

    memset(buff, 0, 4096);
    if (av == NULL)
        return -1;
    if (check_params(av) == 0) {
        make_command_rfc_compatible(buff, "SEND ", av);
        write(socket, buff, strlen(buff));
        memset(buff, 0, 4096);
        read(socket, buff, 4096); // 3 = lenth error code
        client_reply(atoi(buff));
        // atoi -> compare error code
    } else  {
        printf("Command are not good use /help for more information !\n");
    }
    return 0;
}

/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_cmd_logout
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int logout_client(char *av, int socket)
{
    char code_response[3];
    char **tab_res = NULL;

    if (check_params(av) == 0)
        tab_res = send_command(av, tab_res, "LOGO ", socket);
    else {
        printf("Command are not good use /help for more information !\n");
        return -1;
    }
    if (tab_res == NULL) {
        printf("Tab_res == NULL\n");
        free(tab_res);
        return -1;
    }
    strncpy(code_response, tab_res[0], 2);
    code_response[2] = '\0';
    if (!strcmp(code_response, "15"))
        client_event_logged_out(tab_res[1], tab_res[3]);
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    free(tab_res);
    return 0;
}

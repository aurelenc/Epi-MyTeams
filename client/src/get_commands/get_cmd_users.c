/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** get_cmd_users
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int users(char *av, int socket)
{
    char code_response[3];
    char **tab_res = NULL;

    if (check_params(av) == 0)
        tab_res = send_command(av, tab_res, "USRS ", socket);
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
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    if (!strcmp(code_response, "00")) //print_list_of_user
        for (int i = 0; tab_res[i + 6]; i = i + 7)
            client_print_users(tab_res[i + 1], tab_res[i + 3], atoi(tab_res[i + 5]));
    free(tab_res);
    return 0;
}

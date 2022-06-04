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

int users_responses(char **tab, char *code_response)
{
    if (!strcmp(code_response, "13"))
        client_error_unauthorized();
    printf("merdfe\n");
    if (!strcmp(code_response, "00"))
        for (int i = 0; tab[i + 6]; i = i + 6)
            client_print_users(tab[i + 1], tab[i + 3], atoi(tab[i + 5]));
    free(tab);
    return 0;
}

int users(char *av, int socket)
{
    char code_response[3] = {0};
    char **tab_res = NULL;

    if (check_params(av) == 0)
        tab_res = send_command(av, tab_res, "USRS ", socket);
    else {
        printf("Command is not good, use /help for more information !\n");
        return -1;
    }
    if (tab_res == NULL) {
        printf("Tab_res == NULL\n");
        free(tab_res);
        return -1;
    }
    strncpy(code_response, tab_res[0], 2);
    return users_responses(tab_res, code_response);
}

/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** parse_server_response
*/

#include "get_command.h"

int count_users(char *response)
{
    int nb_users = 0;

    for (int i = 0; response[i] != '\0'; i++)
        if (response[i] == '[')
            nb_users++;
    return nb_users;
}

int is_arg_good(char *response, int nb_params)
{
    int count = 0;
    int check = 0;

    for (int i = 0; response[i] != '\0'; i++) {
        if (response[i] == '"' && check == 0)
            check++;
        if (response[i] == '"' && check == 1)
            check--;
        if (response[i] == ' ' && check == 0)
            count++;
    }
    return count;
}

// printf("%d: [%s]\n", i, arg); add line 54 for print all params
char **parse_response(char *response, int nb_params)
{
    char *arg = NULL;
    char *str1 = strdup(response);
    char *saveptr1 = NULL;
    char *parser = "\"";
    char **tab_response =
    calloc(sizeof(char *), ((count_users(response) *
    (nb_params = is_arg_good(response, nb_params))) * 2 + 1) * 2);

    if (count_users(response) == 0)
        return(NULL);
    if (nb_params == 0)
        return (NULL);
    for (int i = 0; ; i++, str1 = NULL) {
        arg = strtok_r(str1, parser, &saveptr1);
        if (arg == NULL)
            break;
        printf("%d: [%s]\n", i, arg);
        tab_response[i] = strdup(arg);
    }
    return tab_response;
}

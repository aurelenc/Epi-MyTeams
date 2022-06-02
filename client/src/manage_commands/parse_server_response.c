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

bool is_arg_good(char *response, int nb_params)
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
    if (count == nb_params)
        return true;
    return false;
}

char **parse_response(char *response, int nb_params)
{
    char *arg = NULL;
    char *str1 = response;
    char *saveptr1 = NULL;
    char parser = '"';
    char **tab_response = malloc(sizeof(char *) * (count_users(response) * nb_params));

    printf("response = [%s]\n", response);
    printf("count user = [%i]\n", count_users(response));
    printf("nb_params = [%i]\n", nb_params);
    printf("(count_users(response) * nb_params) = [%i]\n", (count_users(response) * nb_params));
    if (tab_response == NULL)
        exit(0);
    if (!is_arg_good(response, nb_params))
        return NULL;
    for (int i = 1; ; i++, str1 = NULL) {
        arg = strtok_r(str1, &parser, &saveptr1);
        if (arg == NULL)
            break;
        printf("%d: [%s]\n", i, arg);
        tab_response[i - 1] = malloc(sizeof(char) * strlen(arg));
        memcpy(tab_response[i - 1], arg, strlen(arg));
    }
    return tab_response;
}

/*
** EPITECH PROJECT, 2022
** My_Teams
** File description:
** get_cmd_login
*/

#include <unistd.h>
#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

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

    for (int i = 0; i != '\0'; i++) {
        if (response[i] == ' ' && check == 0)
            count++;
        if (response[i] == '"' && check == 0)
            check++;
        if (response[i] == '"' && check == 1)
            check--;
    }
    if (count == nb_params)
        return true;
    return false;
}

char **parse_response(char *response, int nb_params)
{
    char *arg;
    char *str1;
    char *saveptr1;
    int j = 0;
    char **tab_response = malloc(sizeof(char *) * (count_users(response) * nb_params));

    if (!is_arg_good(response, nb_params))
        return NULL;

    for (int i = 1, str1 = response[1]; ; i++, str1 = NULL) {
        arg = strtok_r(str1, response[2], &saveptr1);
        if (arg == NULL)
            break;
        printf("%d: %s\n", j, arg);
        if ((i % 2) == 0)
            memcpy(tab_response[i], arg, strlen(arg));
    }
    return tab_response;
}

int login_client(char *av, int socket)
{
    char buff[4096];
    char response[2];
    char **tab_response;

    memset(buff, 0, 4096);
    if (av == NULL)
        return -1;
    if (check_params(av) == 1) {

        make_command_rfc_compatible(buff, "LOGIN ", av);

        write(socket, buff, strlen(buff));
        memset(buff, 0, 4096);

        if (read(socket, buff, 4096) == 0) {
            printf("Client is deconnected !\n");
            exit (0);
        }

        printf("Response finale du server = [%s]\n", buff);
        client_reply(atoi(strncpy(response, buff, 2)));
        // if (strlen(buff) > 4)
        //     tab_response = parse_response(buff, 2);
        //     client_event_logged_in(tab_response[0], tab_response[1]);
    } else {
        printf("Command are not good use /help for more information !\n");
    }
    return 0;
}
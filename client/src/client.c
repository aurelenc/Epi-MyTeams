/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** client
*/

#include "client.h"
#include "get_command.h"
#include "reply_codes.h"

void connect_client(client_t *client)
{
    if (connect(client->socket,
    (SA*)&client->servaddr, sizeof(client->servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(84);
    } else
        printf("connected to the server..\n");
}

char *get_input_client(char *buff)
{
    for (int i = 0; (buff[i] = getchar()) != '\n'; i++)
        if (buff[i] == EOF || buff[i] == 0)
            exit(0);
    return (buff);
}

void read_message(client_t *client, char *buff)
{
    char **tab_message = NULL;
    char response[2];

    memset(buff, 0, strlen(buff));
    if (read(client->socket, buff, (int)4e+6) <= 0)
        exit(0);
    printf("message = [%s]\n", buff);
    client_reply(atoi(strncpy(response, buff, 2)), tab_message, buff);
}

void running_teams(client_t *client, char *buff)
{
    FD_ZERO(&client->rfd);
    FD_ZERO(&client->wfd);
    FD_SET(client->socket, &client->rfd);
    FD_SET(client->socket, &client->wfd);
    FD_SET(0, &client->rfd);
    if (select(FD_SETSIZE, &client->rfd, &client->wfd, NULL, NULL) < 0)
        exit(84);
    if (FD_ISSET(client->socket, &client->rfd))
        read_message(client, buff);
    if (FD_ISSET(client->socket, &client->wfd)) {
        memset(buff, 0, strlen(buff));
        if (FD_ISSET(0, &client->rfd))
            buff = get_input_client(buff);
        parse_command(buff, client->socket);
        if ((strncmp(buff, "exit", 4)) == 0)
            exit(-16 + ((int) printf("Client Exit ...\n")));
    }
}

int my_teams_client(int ac, char **av)
{
    client_t *client;
    char *buff = calloc(sizeof(char), MAX + 1);

    client = calloc(sizeof(client_t), 1);
    if (client == NULL)
        return (84);
    if (!arg_is_good(ac, av))
        return (84);
    create_client(client, av);
    connect_client(client);
    client->is_connected = true;
    memset(buff, 0, MAX);
    setbuf(stdout, NULL);
    set_sigint_handler();
    while (client->is_connected)
        running_teams(client, buff);
    free(buff);
    return 0;
}

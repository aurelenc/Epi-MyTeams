/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** client
*/

#include "client.h"
#include "get_command.h"

bool arg_is_good(int ac, char **av)
{
    printf("ac = [%i]\n", ac);
    if (ac != 3)
        return false;
    printf("IP = [%s]\n", av[1]);
    if (atoi(av[2]) == 0)
        return false;
    return true;
}

void create_client(client_t *client, char **av)
{
    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&client->servaddr, sizeof(client->servaddr));
    client->servaddr.sin_family = AF_INET;
    client->servaddr.sin_addr.s_addr = inet_addr(av[1]);
    if (client->servaddr.sin_addr.s_addr == -1) {
        printf("IP is not good, try with a good IP address...\n");
        exit(84);
    }
    client->servaddr.sin_port = htons(atoi(av[2]));
}

void connect_client(client_t *client)
{
    if (connect(client->socket, (SA*)&client->servaddr,
        sizeof(client->servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(84);
    }
    else
        printf("connected to the server..\n");
}

void running_teams(client_t *client)
{
    char buff[MAX];

    client->is_connected = true;
    read(client->socket, buff, MAX);
    printf("Buff 1 = [%s]\n", buff);
    memset(buff, 0, MAX);
    while (client->is_connected) {
        bzero(buff, sizeof(buff));
        printf("Enter the command : ");
        for (int i = 0; (buff[i] = getchar()) != '\n'; i++);
        parse_command(buff, client->socket);
        printf("From Server : [%s]\n", buff);
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
            break;
        }
    }
}

int my_teams_client(int ac, char **av)
{
    client_t *client;

    client = malloc(sizeof(client_t));
    if (client == NULL) {
        printf("test01\\n");
        return (84);
    }
    if (!arg_is_good(ac, av)) {
        printf("tedst01\\n");
        return (84);
    }
    create_client(client, av);
    connect_client(client);
    running_teams(client);
    //close_client();
    return 0;
}

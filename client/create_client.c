/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** create_client
*/

#include "client.h"

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

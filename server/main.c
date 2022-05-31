/*
** EPITECH PROJECT, 2021
** Ftp
** File description:
** main.c
*/

#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 80
#define PORT 8080
#define SADR struct sockaddr


// USE PERROR instead printf !!!!

void receive_client_input(int connfd)
{
    char str[MAX];
    int length;
    int i = 0;

    while (1) {
        //empty buff/str
        bzero(str, MAX);

        read(connfd, str, sizeof(str));

        printf("From client: %s\t To client : ", str);

        //empty buff/str
        bzero(str, MAX);
        i = 0;

        // copy server message in the buffer
        while ((str[i++] = getchar()) != '\n');

        // and send that buffer to client
        write(connfd, str, sizeof(str));

        if (strncmp("exit", str, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}

int main()
{
    int sockfiledescr = socket(AF_INET, SOCK_STREAM, 0);
    int socketclient;
    int len;
    struct sockaddr_in servaddr;
    struct sockaddr_in client;

    if (sockfiledescr == -1) {
        printf("Creation of the socket failed...\n");
        return (84);
    }
    else
        printf("Creation of the socket is a success, socket = %i !\n", sockfiledescr);

    // Assign Ip, Port
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if ((bind(sockfiledescr, (SADR*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
    if (listen(sockfiledescr, 5) != 0) { // macros a rajouter
        printf("Listen failed...\n");
        close(sockfiledescr);
        exit(84);
    }
    else
        printf("Server accept the client...\n");

    // Accept the data packet from client and verification
    socketclient = accept(sockfiledescr, (SADR*)&client, &len);

    if (socketclient < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");
    receive_client_input(socketclient);
    close(sockfiledescr);
    return (0);
}

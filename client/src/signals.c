/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** signals
*/

#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>

void handle_sigint(int sig)
{
    signal(sig, SIG_IGN);
    exit(0);
}

void set_sigint_handler(void)
{
    signal(SIGINT, handle_sigint);
}

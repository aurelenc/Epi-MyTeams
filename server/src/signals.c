/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** signals
*/

#include <signal.h>
#include <stdbool.h>

static volatile bool sigint_received = false;

void handle_sigint(int sig)
{
    signal(sig, SIG_IGN);
    sigint_received = true;
}

bool get_sigint_received(void)
{
    return sigint_received;
}

void set_sigint_handler(void)
{
    signal(SIGINT, handle_sigint);
}

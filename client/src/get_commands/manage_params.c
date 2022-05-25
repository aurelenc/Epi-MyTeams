/*
** EPITECH PROJECT, 2022
** 1
** File description:
** manage_params
*/

#include "../../include/get_command.h"

static char *remove_quotes(char *av, int i)
{
    int j = 0;

    if (av[i] == '"' && av[i - 1] != '\\') {
            for (j = i; av[j] != '\0'; j++)
                av[j] = av[j + 1];
            if (av[j] == '\0')
                av[j - 1] = '\0';
    }
    return av;
}
char *manage_params(char *av)
{
    for (int i = 0; av[i] != '\0'; i++)
        av = remove_quotes(av, i);
    return av;
}
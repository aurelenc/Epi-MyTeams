/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_tools
*/

#include <stdbool.h>
#include <string.h>

bool compare(const void *elem, const void *data)
{
    const char *e = (const char *)elem;
    const char *d = (const char *)data;

    if (strcmp(e, d) == 0)
        return true;
    return false;
}

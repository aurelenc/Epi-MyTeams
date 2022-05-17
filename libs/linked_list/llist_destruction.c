/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** llist_destruction
*/

#include "llist.h"
#include <stdlib.h>

llist_t *llist_destruction(llist_t *list)
{
    llist_clear(list);
    free(list);
    return 0;
}

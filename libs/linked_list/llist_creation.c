/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** llist_creation
*/

#include "llist.h"
#include <stdlib.h>

llist_t *llist_init(void)
{
    llist_t *new_list = calloc(sizeof(llist_t), 1);

    if (!new_list)
        return (NULL);
    new_list->first = NULL;
    return (new_list);
}

/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** llist_access
*/

#include "llist.h"
#include "llist_tools.h"


void *llist_front(llist_t *list)
{
    if (llist_is_empty(list))
        return 0;
    return list->first->data;
}

void *llist_back(llist_t *list)
{
    node_t *ptr;

    if (!list)
        return 0;
    ptr = list->first;
    while (ptr && ptr->next)
        ptr = ptr->next;
    if (ptr)
        return ptr->data;
    else
        return 0;
}

void *llist_get(llist_t *list, unsigned int position)
{
    node_t *ptr;

    if (!list)
        return 0;
    ptr = llist_take_node_at_position(list, position);
    if (ptr)
        return ptr->data;
    else
        return 0;
}

/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** llist_tools
*/

#include "llist.h"

node_t *llist_take_node_at_position(llist_t *list, unsigned int position)
{
    node_t *ptr;
    unsigned int i = 0;

    if (!list || position >= list_get_size(list))
        return 0;
    ptr = list->first;
    while (ptr && ptr->next && i < position) {
        ptr = ptr->next;
        i++;
    }
    if (ptr && i == position)
        return ptr;
    else
        return 0;
}

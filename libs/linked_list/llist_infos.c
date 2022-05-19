/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** llist_infos
*/

#include "llist.h"

unsigned int llist_get_size(llist_t *list)
{
    int length = 0;
    node_t *ptr;

    if (!list)
        return 0;
    ptr = list->first;
    while (ptr) {
        length++;
        ptr = ptr->next;
    }
    return length;
}

bool llist_is_empty(llist_t *list)
{
    return (llist_get_size(list) == 0);
}

void llist_dump(llist_t *list, data_displayer_t val_disp)
{
    node_t *ptr;

    if (!list)
        return;
    ptr = list->first;
    while (ptr) {
        val_disp(ptr->data);
        ptr = ptr->next;
    }
}

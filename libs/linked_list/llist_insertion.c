/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** llist_insertion
*/

#include "llist.h"
#include "llist_tools.h"
#include <stdlib.h>

bool llist_push_front(llist_t *list, void *elem)
{
    node_t *new_node;

    if (!list)
        return false;
    new_node = calloc(sizeof(*new_node), 1);
    if (!new_node)
        return false;
    new_node->data = elem;
    new_node->next = list->first;
    list->first = new_node;
    return true;
}

bool llist_append(llist_t *list, void *elem)
{
    node_t *new_node;
    node_t *ptr;

    if (!list)
        return false;
    new_node = calloc(sizeof(*new_node), 1);
    if (!new_node)
        return false;
    ptr = list->first;
    while (ptr && ptr->next) {
        ptr = ptr->next;
    }
    new_node->data = elem;
    new_node->next = 0;
    if (ptr)
        ptr->next = new_node;
    else
        list->first = new_node;
    return true;
}

bool llist_insert(llist_t *list, void *elem, unsigned int position)
{
    node_t *new_node;
    node_t *ptr;

    if (!list)
        return false;
    if (position == 0)
        return llist_push_front(list, elem);
    new_node = calloc(sizeof(*new_node), 1);
    if (!new_node)
        return false;
    ptr = llist_take_node_at_position(list, position - 1);
    if (ptr) {
        new_node->data = elem;
        new_node->next = ptr->next;
        ptr->next = new_node;
        return true;
    } else
        return false;
}

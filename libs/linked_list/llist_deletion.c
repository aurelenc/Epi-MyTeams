/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** llist_deletion
*/

#include "llist.h"
#include "llist_tools.h"
#include <stdlib.h>

bool llist_pop_front(llist_t *list)
{
    node_t *temp;

    if (!list)
        return false;
    temp = list->first;
    if (temp) {
        list->first = temp->next;
        free(temp);
        return true;
    } else
        return false;
}

bool llist_pop_back(llist_t *list)
{
    node_t *ptr;

    if (!list || !list->first)
        return 0;
    ptr = list->first;
    if (!ptr->next) {
        free(ptr);
        list->first = 0;
        return true;
    }
    while (ptr && ptr->next && ptr->next->next)
        ptr = ptr->next;
    free(ptr->next);
    ptr->next = 0;
    return false;
}

bool llist_delete_at(llist_t *list, unsigned int position)
{
    node_t *prev;
    node_t *node;

    if (!list)
        return false;
    if (position == 0)
        return llist_pop_front(list);
    prev = llist_take_node_at_position(list, position - 1);
    node = llist_take_node_at_position(list, position);
    if (!node)
        return 0;
    prev->next = node->next;
    free(node);
    return 1;
}

bool llist_delif(llist_t *list, data_search_t search_fun, const void *search)
{
    node_t *ptr;
    unsigned int count = 0;

    if (!list)
        return (0);
    ptr = list->first;
    while (ptr) {
        if (search_fun(ptr->data, search))
            break;
        ptr = ptr->next;
        count ++;
    }
    return (llist_delete_at(list, count));
}

void llist_clear(llist_t *list)
{
    while (list->first)
        llist_pop_front(list);
}

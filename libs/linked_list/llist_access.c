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

void *llist_search(llist_t *list, data_search_t search_fun, const void *search)
{
    node_t *ptr;

    if (!list)
        return (0);
    ptr = list->first;
    while (ptr) {
        if (search_fun(ptr->data, search))
            return (ptr->data);
        ptr = ptr->next;
    }
    return (ptr);
}

llist_t *llist_multiple_search(llist_t *list, data_search_t search_fun, const void *search)
{
    node_t *ptr;
    llist_t *found = llist_init();

    if (!found)
        return (0);
    if (!list)
        return (found);
    ptr = list->first;
    while (ptr) {
        if (search_fun(ptr->data, search))
            llist_append(found, (ptr->data));
        ptr = ptr->next;
    }
    return (found);
}

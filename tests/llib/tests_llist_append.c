/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_llist_append
*/

#include <criterion/criterion.h>
#include "llist.h"

Test (list_of_one_elem, llist_append)
{
    llist_t *list = llist_init();

    llist_append(list, strdup("5"));
    cr_assert_eq(1, llist_get_size(list));
    cr_assert_str_eq("5", list->first->data);
}

Test (list_of_more_than_one_elem, llist_append)
{
    llist_t *list = llist_init();

    llist_append(list, "5");
    llist_append(list, "2");
    llist_append(list, "10");
    cr_assert_eq(3, llist_get_size(list));
    cr_assert_str_eq("5", list->first->data);
    cr_assert_str_eq("2", list->first->next->data);
    cr_assert_str_eq("10", list->first->next->next->data);
}

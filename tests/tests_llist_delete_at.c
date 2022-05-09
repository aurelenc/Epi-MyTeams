/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_llist_delete_at
*/

#include <criterion/criterion.h>
#include "llist.h"

Test (list_of_one_elem, llist_delete_at)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    cr_assert_eq(1, llist_delete_at(list, 0));
    cr_assert_eq(0, list->first);
}

Test (out_of_bounds, llist_delete_at)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    cr_assert_eq(0, llist_delete_at(list, 1));
    cr_assert_str_eq("5", list->first->data);
}

Test (empty_list, llist_delete_at)
{
    llist_t *list = llist_init();

    cr_assert_eq(0, llist_delete_at(list, 0));
    cr_assert_eq(0, list->first);
}

Test (list_of_more_than_one_elem, llist_delete_at)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    llist_push_front(list, "2");
    llist_push_front(list, "10");
    llist_delete_at(list, 1);
    cr_assert_str_eq("5", llist_get(list, 1));
    cr_assert_eq(2, llist_get_size(list));
}

Test (none_list, llist_delete_at)
{
    llist_t *list = 0;

    cr_assert_eq(0, llist_delete_at(list, 2));
}

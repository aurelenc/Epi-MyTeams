/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_llist_insert
*/

#include <criterion/criterion.h>
#include "llist.h"

Test (list_of_one_elem, llist_insert)
{
    llist_t *list = llist_init();

    llist_insert(list, "5", 0);
    cr_assert_eq(1, llist_get_size(list));
    cr_assert_str_eq("5", list->first->data);
}

Test (out_of_bound, llist_insert)
{
    llist_t *list = llist_init();

    cr_assert_eq(0, llist_insert(list, "5", 5));
    cr_assert_eq(0, llist_get_size(list));
}

Test (list_of_more_than_one_elem, llist_insert)
{
    llist_t *list = llist_init();

    llist_append(list, "5");
    llist_append(list, "4");
    llist_append(list, "3");
    llist_append(list, "2");
    llist_insert(list, "10", 1);
    cr_assert_eq(5, llist_get_size(list));
    cr_assert_str_eq("5", list->first->data);
    cr_assert_str_eq("10", list->first->next->data);
    cr_assert_str_eq("4", list->first->next->next->data);
}

Test (long_list, llist_insert)
{
    llist_t *list = llist_init();

    llist_append(list, "8");
    llist_append(list, "7");
    llist_append(list, "6");
    llist_append(list, "5");
    llist_append(list, "4");
    llist_append(list, "3");
    llist_append(list, "2");
    llist_append(list, "1");
    llist_insert(list, "10", 6);
    cr_assert_eq(9, llist_get_size(list));
    cr_assert_str_eq("10", llist_get(list, 6));
}

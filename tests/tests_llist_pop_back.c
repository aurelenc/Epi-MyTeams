/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_llist_pop_back
*/

#include <criterion/criterion.h>
#include "llist.h"

Test (list_of_one_elem, llist_pop_back)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    cr_assert_eq(1, llist_pop_back(list));
    cr_assert_eq(0, list->first);
}

Test (empty_list, llist_pop_back)
{
    llist_t *list = llist_init();

    cr_assert_eq(0, llist_pop_back(list));
    cr_assert_eq(0, list->first);
}

Test (list_of_more_than_one_elem, llist_pop_back)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    llist_push_front(list, "2");
    llist_pop_back(list);
    cr_assert_str_eq("2", llist_back(list));
    cr_assert_eq(1, llist_get_size(list));
}

Test (long_list, llist_pop_back)
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
    llist_pop_back(list);
    cr_assert_str_eq("2", llist_back(list));
    cr_assert_eq(7, llist_get_size(list));
}

Test (none_list, llist_pop_back)
{
    llist_t *list = 0;

    cr_assert_eq(0, llist_pop_back(list));
}

Test (none_data, llist_pop_back)
{
    llist_t *list = llist_init();

    cr_assert_eq(0, llist_pop_back(list));
}

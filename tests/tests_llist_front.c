/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_llist_front
*/

#include <criterion/criterion.h>
#include "llist.h"

Test (empty_list, llist_front)
{
    llist_t *list = llist_init();

    cr_assert_eq(0, llist_front(list));
}

Test (list_of_one_elem, llist_front)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    cr_assert_str_eq("5", llist_front(list));
}

Test (list_of_more_than_one_elem, llist_front)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    llist_push_front(list, "2");
    llist_push_front(list, "10");
    cr_assert_str_eq("10", llist_front(list));
}

Test (none_list, llist_front)
{
    llist_t *list = 0;

    cr_assert_eq(0, llist_front(list));
}

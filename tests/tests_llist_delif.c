/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_llist_delif
*/


#include <criterion/criterion.h>
#include "llist.h"
#include "tests_tools.h"

Test (list_of_one_elem, llist_delif)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    cr_assert_eq(1, llist_delif(list, &compare, "5"));
    cr_assert_eq(0, list->first);
}

Test (none_list, llist_delif)
{
    llist_t *list = 0;

    cr_assert_eq(0, llist_delif(list, &compare, "5"));
}

Test (list_of_more_than_one_elem, llist_delif)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    llist_push_front(list, "2");
    llist_push_front(list, "10");
    cr_assert_eq(1, llist_delif(list, &compare, "2"));
    cr_assert_str_eq("5", llist_get(list, 1));
    cr_assert_eq(NULL, llist_get(list, 2));
    cr_assert_eq(2, llist_get_size(list));
}

Test (does_not_exists, llist_delif)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    llist_push_front(list, "2");
    llist_push_front(list, "10");
    cr_assert_eq(0, llist_delif(list, &compare, "8"));
    cr_assert_eq(3, llist_get_size(list));
}

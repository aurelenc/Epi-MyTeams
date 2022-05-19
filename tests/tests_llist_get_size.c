/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_llist_get_size
*/

#include <criterion/criterion.h>
#include "llist.h"

Test (empty_list, llist_get_size)
{
    llist_t *list = llist_init();

    cr_assert_eq(0, llist_get_size(list));
}

Test (normal_list, llist_get_size)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    llist_push_front(list, "2");
    llist_push_front(list, "10");
    cr_assert_eq(3, llist_get_size(list));
}

Test (none_list, llist_get_size)
{
    llist_t *list = 0;

    cr_assert_eq(0, llist_get_size(list));
}

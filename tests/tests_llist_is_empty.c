/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_llist_is_empty
*/

#include <criterion/criterion.h>
#include "llist.h"

Test (empty_list, llist_is_empty)
{
    llist_t *list = llist_init();

    cr_assert_eq(1, llist_is_empty(list));
}

Test (normal_list, llist_is_empty)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    llist_push_front(list, "2");
    llist_push_front(list, "10");
    cr_assert_eq(0, llist_is_empty(list));
}

/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_llist_clear
*/

#include <criterion/criterion.h>
#include "llist.h"

Test (normal_test, llist_clear)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    llist_push_front(list, "2");
    llist_push_front(list, "10");
    llist_clear(list);
    cr_assert_eq(0, list->first);
}

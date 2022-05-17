/*
** EPITECH PROJECT, 2022
** Linked List Destruction
** File description:
** tests_llist_destruction
*/

#include <criterion/criterion.h>
#include "llist.h"

Test (destroy_a_list, llist_destruction)
{
    llist_t *list = llist_init();

    llist_push_front(list, "5");
    cr_assert_eq(1, llist_get_size(list));
    list = llist_destruction(list);
    cr_assert_eq(0, list);
}

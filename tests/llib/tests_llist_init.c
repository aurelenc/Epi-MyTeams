/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_llist_init
*/

#include <criterion/criterion.h>
#include "llist.h"

Test (llist_initialization, llist_init)
{
    llist_t *list = llist_init();

    cr_assert_not_null(list);
    cr_assert_eq(list->first, 0);
}

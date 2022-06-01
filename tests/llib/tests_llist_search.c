/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_llist_search
*/

#include "llist.h"
#include "tests_tools.h"
#include <criterion/criterion.h>


Test (good_search, llist_search)
{
    llist_t *list = llist_init();

    llist_push_front(list, "Salut");
    llist_push_front(list, "Hello");
    cr_assert_str_eq("Hello", llist_search(list, &compare, "Hello"));
}

Test (none_list, llist_search)
{
    llist_t *list = 0;

    cr_assert_eq(0, llist_search(list, &compare, "Hello"));
}

Test (search_not_found, llist_search)
{
    llist_t *list = llist_init();

    llist_push_front(list, "Salut");
    llist_push_front(list, "Hello");
    cr_assert_eq(0, llist_search(list, &compare, "Holla"));
}

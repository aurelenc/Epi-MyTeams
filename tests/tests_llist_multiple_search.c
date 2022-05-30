/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_llist_multiple_search
*/

#include "llist.h"
#include "tests_tools.h"
#include <criterion/criterion.h>


Test (good_search, llist_multiple_search)
{
    llist_t *list = llist_init();
    llist_t *found = 0;

    llist_append(list, "Salut");
    llist_append(list, "Hello");
    llist_append(list, "Hella");
    found = llist_multiple_search(list, &compare, "Hel");
    cr_assert_eq(2, llist_get_size(found));
    cr_assert_str_eq("Hello", llist_get(found, 0));
    cr_assert_str_eq("Hella", llist_get(found, 1));
}

Test (none_list, llist_multiple_search)
{
    llist_t *list = 0;
    llist_t *found = 0;

    found = llist_multiple_search(list, &compare, "Hel");
    cr_assert_eq(0, llist_get_size(found));
}

Test (search_not_found, llist_multiple_search)
{
    llist_t *list = llist_init();
    llist_t *found = 0;

    llist_append(list, "Salut");
    llist_append(list, "Hello");
    llist_append(list, "Hella");
    found = llist_multiple_search(list, &compare, "Hol");
    cr_assert_eq(0, llist_get_size(found));
}

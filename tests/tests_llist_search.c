/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_llist_search
*/

#include "llist.h"
#include <criterion/criterion.h>
#include <string.h>

static bool compare(const void *elem, const void *data)
{
    const char *e = (const char *)elem;
    const char *d = (const char *)data;

    if (strcmp(e, d) == 0)
        return true;
    return false;
}

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

Test (search_not_find, llist_search)
{
    llist_t *list = llist_init();

    llist_push_front(list, "Salut");
    llist_push_front(list, "Hello");
    cr_assert_eq(0, llist_search(list, &compare, "Holla"));
}

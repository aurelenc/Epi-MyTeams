/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_llist_dump
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "llist.h"

static void int_displayer (const void *data)
{
    int value = *((const int*) data ) ;
    printf ("%d\n", value ) ;
}

Test (normal_list, llist_dump, .init=cr_redirect_stdout)
{
    llist_t *list = llist_init();
    int a = 5;
    int b = 2;
    int c = 10;

    llist_push_front(list, &a);
    llist_push_front(list, &b);
    llist_push_front(list, &c);
    llist_dump(list, int_displayer);
    fflush(0);
    cr_assert_stdout_eq_str("10\n2\n5\n");
}

Test (none_list, llist_dump, .init=cr_redirect_stdout)
{
    llist_t *list = 0;

    llist_dump(list, int_displayer);
    printf("RIP\n");
    fflush(0);
    cr_assert_stdout_eq_str("RIP\n");
}

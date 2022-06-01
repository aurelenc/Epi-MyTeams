/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** tests_llist_take_node_at_position
*/

#include <criterion/criterion.h>
#include "llist.h"
#include "llist_tools.h"

Test (list_of_one_elem, llist_take_node_at_position)
{
    llist_t *list = llist_init();
    node_t *ptr;

    llist_push_front(list, "5");
    ptr = llist_take_node_at_position(list, 0);
    cr_assert_str_eq("5", ptr->data);
}

Test (out_of_bounds, llist_take_node_at_position)
{
    llist_t *list = llist_init();
    node_t *ptr;

    llist_push_front(list, "5");
    ptr = llist_take_node_at_position(list, 1);
    cr_assert_eq(0, ptr);
}

Test (empty_list, llist_take_node_at_position)
{
    llist_t *list = llist_init();
    node_t *ptr = llist_take_node_at_position(list, 0);

    cr_assert_eq(0, ptr);
}

Test (list_of_more_than_one_elem, llist_take_node_at_position)
{
    llist_t *list = llist_init();
    node_t *ptr;

    llist_push_front(list, "5");
    llist_push_front(list, "2");
    llist_push_front(list, "10");
    ptr = llist_take_node_at_position(list, 1);
    cr_assert_str_eq("2", ptr->data);
}

Test (none_list, llist_take_node_at_position)
{
    llist_t *list = 0;
    node_t *ptr = llist_take_node_at_position(list, 0);

    cr_assert_eq(0, ptr);
}

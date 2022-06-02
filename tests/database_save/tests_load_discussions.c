/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_load_discussions
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "llist.h"
#include "database_management.h"
#include "tables/discussions/discussion.h"
#include "tables/discussions/database_discussions_save.h"
#include <stdio.h>

Test (load_a_basic_db, db_load_discussions)
{
    database_t *db = db_creation();
    discussion_t *disc = 0;

    cr_assert_eq(db_load_discussions(db, "tests/test_files/discussions_load.csv"), true);
    disc = (discussion_t *)db->discussions->first->data;
    cr_assert_eq(disc->id, 1);
    cr_assert_str_eq(disc->uuid, "UUID1");
    disc = (discussion_t *)db->discussions->first->next->data;
    cr_assert_eq(disc->id, 2);
    cr_assert_eq(disc->user_one_id, 20);
    disc = (discussion_t *)db->discussions->first->next->next->data;
    cr_assert_eq(disc->id, 3);
    cr_assert_eq(disc->user_two_id, 300);
}

/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_save_discussions
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "llist.h"
#include "database_management.h"
#include "tables/discussions/discussion.h"
#include "tables/discussions/database_discussions_save.h"
#include <stdio.h>

Test (save_a_basic_db, db_save_discussions)
{
    database_t *db = db_creation();
    discussion_t *discussion = 0;

    discussion = discussion_init(1, 10, 100);
    discussion->uuid = strdup("UUID1");
    llist_append(db->discussions, discussion);
    discussion = discussion_init(2, 20, 200);
    discussion->uuid = strdup("2uuid");
    llist_append(db->discussions, discussion);

    cr_assert_eq(db_save_discussions(db, "tests/test_files/discussions.csv"), true);
    cr_assert_str_eq(get_file_content("tests/test_files/discussions.csv"), "\"1\";\"UUID1\";\"10\";\"100\";\n\"2\";\"2uuid\";\"20\";\"200\";\n");
    db_destruction(db);
}

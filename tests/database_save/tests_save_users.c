/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_save_users
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "llist.h"
#include "database_management.h"
#include "tables/users/user.h"
#include "tables/users/database_users_save.h"
#include <stdio.h>

Test (save_a_basic_db, db_save_users)
{
    database_t *db = db_creation();
    user_t *user = 0;

    user = user_init(1, "10", "100");
    user->uuid = strdup("UUID1");
    llist_append(db->users, user);
    user = user_init(2, "20", "200");
    user->uuid = strdup("2uuid");
    llist_append(db->users, user);

    cr_assert_eq(db_save_users(db, "tests/test_files/users.csv"), true);
    cr_assert_str_eq(get_file_content("tests/test_files/users.csv"), "\"1\";\"UUID1\";\"10\";\"100\";\n\"2\";\"2uuid\";\"20\";\"200\";\n");
    db_destruction(db);
}

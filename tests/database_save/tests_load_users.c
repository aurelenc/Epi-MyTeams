/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_load_users
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "database_management.h"
#include "tables/users/user.h"
#include "tables/users/database_users_save.h"
#include <stdio.h>

Test (load_a_basic_db, db_load_users)
{
    database_t *db = db_creation();
    user_t *user = 0;

    cr_assert_eq(db_load_users(db, "tests/test_files/users_load.csv"), true);
    user = (user_t *)db->users->first->data;
    cr_assert_eq(user->id, 1);
    cr_assert_str_eq(user->uuid, "UUID1");
    user = (user_t *)db->users->first->next->data;
    cr_assert_eq(user->id, 2);
    cr_assert_str_eq(user->pseudo, "2NAME");
    user = (user_t *)db->users->first->next->next->data;
    cr_assert_eq(user->id, 3);
    cr_assert_str_eq(user->password, "D3sc");
    db_destruction(db);
}

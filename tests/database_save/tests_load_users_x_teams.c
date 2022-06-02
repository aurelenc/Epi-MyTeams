/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_load_users
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "database_management.h"
#include "tables/users_x_teams/users_x_teams.h"
#include "tables/users_x_teams/database_users_x_teams_save.h"
#include <stdio.h>

Test (load_a_basic_db, db_load_users_x_teams)
{
    database_t *db = db_creation();
    id_pair_t *pair = 0;

    cr_assert_eq(db_load_users_x_teams(db, "tests/test_files/users_x_teams_load.csv"), true);
    pair = (id_pair_t *)db->users_teams->first->data;
    cr_assert_eq(pair->user_id, 1);
    cr_assert_eq(pair->team_id, 100);
    pair = (id_pair_t *)db->users_teams->first->next->data;
    cr_assert_eq(pair->user_id, 2);
    cr_assert_eq(pair->team_id, 200);
    pair = (id_pair_t *)db->users_teams->first->next->next->data;
    cr_assert_eq(pair->user_id, 3);
    cr_assert_eq(pair->team_id, 300);
    db_destruction(db);
}

/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_save_users_x_teams
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "llist.h"
#include "database_management.h"
#include "tables/users_x_teams/users_x_teams.h"
#include "tables/users_x_teams/database_users_x_teams_save.h"
#include <stdio.h>

Test (save_a_basic_db, db_save_users_x_teams)
{
    database_t *db = db_creation();
    id_pair_t *pair = 0;

    pair = calloc(sizeof(id_pair_t), 1);
    pair->user_id = 1;
    pair->team_id = 100;
    llist_append(db->users_teams, pair);
    pair = calloc(sizeof(id_pair_t), 1);
    pair->user_id = 2;
    pair->team_id = 200;
    llist_append(db->users_teams, pair);

    cr_assert_eq(db_save_users_x_teams(db, "tests/test_files/users_x_teams.csv"), true);
    cr_assert_str_eq(get_file_content("tests/test_files/users_x_teams.csv"), "\"1\";\"100\";\n\"2\";\"200\";\n");
    db_destruction(db);
}

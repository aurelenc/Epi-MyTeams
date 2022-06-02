/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_save_teams
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "llist.h"
#include "database_management.h"
#include "tables/teams/team.h"
#include "tables/teams/database_teams_save.h"
#include <stdio.h>

Test (save_a_basic_db, db_save_teams)
{
    database_t *db = db_creation();
    team_t *team = 0;

    team = team_init(1, "10", "100");
    team->uuid = strdup("UUID1");
    llist_append(db->teams, team);
    team = team_init(2, "20", "200");
    team->uuid = strdup("2uuid");
    llist_append(db->teams, team);

    cr_assert_eq(db_save_teams(db, "tests/test_files/teams.csv"), true);
    cr_assert_str_eq(get_file_content("tests/test_files/teams.csv"), "\"1\";\"UUID1\";\"10\";\"100\";\n\"2\";\"2uuid\";\"20\";\"200\";\n");
    db_destruction(db);
}

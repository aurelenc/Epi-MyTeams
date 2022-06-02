/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_load_teams
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "database_management.h"
#include "tables/teams/team.h"
#include "tables/teams/database_teams_save.h"
#include <stdio.h>

Test (load_a_basic_db, db_load_teams)
{
    database_t *db = db_creation();
    team_t *team = 0;

    cr_assert_eq(db_load_teams(db, "tests/test_files/teams_load.csv"), true);
    team = (team_t *)db->teams->first->data;
    cr_assert_eq(team->id, 1);
    cr_assert_str_eq(team->uuid, "UUID1");
    team = (team_t *)db->teams->first->next->data;
    cr_assert_eq(team->id, 2);
    cr_assert_str_eq(team->name, "2NAME");
    team = (team_t *)db->teams->first->next->next->data;
    cr_assert_eq(team->id, 3);
    cr_assert_str_eq(team->desc, "D3sc");
    db_destruction(db);
}

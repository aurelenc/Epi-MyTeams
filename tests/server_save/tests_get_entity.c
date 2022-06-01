/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_get_entity
*/

#include <criterion/criterion.h>
#include "save.h"
#include <stdio.h>

Test (get_the_first_entity, get_entity)
{
    char *buffer = strdup("gloubiboulga[\"6a36151e-7e68-4264-a5da-b7d3fe646288\" \"name\" \"1\"]it's over");
    char *entity = get_entity(buffer);

    cr_assert_str_eq(entity, "\"6a36151e-7e68-4264-a5da-b7d3fe646288\" \"name\" \"1\"");
}

Test (no_entity_start, get_entity)
{
    char *buffer = strdup("\"6a36151e-7e68-4264-a5da-b7d3fe646288\" \"name\" \"1\"]it's over");
    char *entity = get_entity(buffer);

    cr_assert_eq(entity, NULL);
}

Test (no_entity_end, get_entity)
{
    char *buffer = strdup("gloubiboulga[\"6a36151e-7e68-4264-a5da-b7d3fe646288\" \"name\" \"1\"");
    char *entity = get_entity(buffer);

    cr_assert_eq(entity, NULL);
}

Test (no_string, get_entity)
{
    char *buffer = 0;
    char *entity = get_entity(buffer);

    cr_assert_eq(entity, NULL);
}

Test (empty_string_string, get_entity)
{
    char *buffer = strdup("\0");
    char *entity = get_entity(buffer);

    cr_assert_eq(entity, NULL);
}

Test (fake_entity_start, get_entity)
{
    char *buffer = strdup("[6a36151e-7e68-4264-a5da-b7d3fe646288\" [\"name\" \"1\"]it's over");
    char *entity = get_entity(buffer);

    cr_assert_str_eq(entity, "\"name\" \"1\"");
}

Test (fake_entity_end, get_entity)
{
    char *buffer = strdup("gloubiboulga[\"6a36151e-7e68-4264-a5da-b7d3fe646288]\" \"name\" \"1\"]");
    char *entity = get_entity(buffer);

    cr_assert_str_eq(entity, "\"6a36151e-7e68-4264-a5da-b7d3fe646288]\" \"name\" \"1\"");
}

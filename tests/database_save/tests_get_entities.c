/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_get_entities
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tables/load_functions.h"
#include <stdio.h>

Test (normal, get_entities)
{
    char *buffer = strdup("\"1\";\"UUID1\";\"name\";\"desc1\";\"10\";\n\"2\";\"2uuid\";\"forname\";\"2DESC\";\"20\";\n");
    char ***entities = get_entities(buffer, 5);


    cr_assert_not_null(buffer);
    cr_assert_str_eq(entities[0][0], "1");
    cr_assert_str_eq(entities[0][3], "desc1");
    cr_assert_str_eq(entities[1][1], "2uuid");
    cr_assert_str_eq(entities[1][4], "20");
}

Test (corrupted_datas, get_entities)
{
    char *buffer = strdup("\"1\";\"UUID1\";\"name\";\"desc1\";\"10\";\n\"2\";2uuid\";\"forname\";\"2DESC\";\"20\";\n");
    char ***entities = get_entities(buffer, 5);


    cr_assert_null(entities);
}

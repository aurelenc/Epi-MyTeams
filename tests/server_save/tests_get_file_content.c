/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_get_entity
*/

#include <criterion/criterion.h>
#include "save.h"

Test (get_the_content_of_a_file, get_file_content)
{
    char *buffer = get_file_content("tests/test_files/test_save.csv");

    cr_assert_str_eq(buffer, "\"1\";\"UUID1\";\"name\";\"10\";\n");
}

Test (file_does_not_exist, get_file_content)
{
    char *buffer = get_file_content("NOPE");

    cr_assert_eq(buffer, NULL);
}

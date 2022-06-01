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
    char *buffer = get_file_content("tests/test_files/test_save.txt");

    cr_assert_str_eq(buffer, "[\"6a36151e-7e68-4264-a5da-b7d3fe646288\" \"name\" \"1\"]\n");
}

Test (file_does_not_exist, get_file_content)
{
    char *buffer = get_file_content("NOPE");

    cr_assert_eq(buffer, NULL);
}

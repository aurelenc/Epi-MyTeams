/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_get_arg
*/

#include <criterion/criterion.h>
#include "save.h"
#include <stdio.h>

Test (no_arg, get_arg)
{
    char *buffer = strdup("6a36151e-7e68-4264-a5da-b7d3fe646288 name 1");
    char *arg = get_arg(buffer);

    cr_assert_eq(arg, NULL);
}

Test (first_arg, get_arg)
{
    char *buffer = strdup("\"6a36151e-7e68-4264-a5da-b7d3fe646288\" \"name\" \"1\"");
    char *arg = get_arg(buffer);

    cr_assert_str_eq(arg, "6a36151e-7e68-4264-a5da-b7d3fe646288");
}

Test (arg_does_not_fished, get_arg)
{
    char *buffer = strdup("\"6a36151e-7e68-4264-a5da-b7d3fe646288 name 1");
    char *arg = get_arg(buffer);

    cr_assert_eq(arg, NULL );
}

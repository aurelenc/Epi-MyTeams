/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** base_test
*/

#include <criterion/criterion.h>

Test(github, action)
{
    char test[4] = {1, 2, 3, 4};

    cr_assert(test[2] == 2[test]);
}

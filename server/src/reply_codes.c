/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** reply_codes
*/

#include "reply_codes.h"

const reply_code_t reply_codes[] = {
    {200, "200 Success\n"},
    {220, "220 Service ready for new user.\n"},
    {550, "550 Requested action not taken.\n"},
    {10068, "10068 Too many users, server is full.\n"},
    {0, "0 Invalid error code\n"}
};

int get_reply(int code)
{
    int i = 0;

    for (; reply_codes[i].code != 0; i++) {
        if (reply_codes[i].code == code)
            return i;
    }
    return i;
}

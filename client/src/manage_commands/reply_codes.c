/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** reply_codes
*/

#include "reply_codes.h"

const reply_code_t reply_codes[] = {
    {00, "00:Success\n"},
    {01, "01:Service ready for new user.\n"},
    {10, "10:Internal server error.\n"},
    {11, "11:Server is full.\n"},
    {12, "12:Too many requests.\n"},
    {13, "13:Forbidden.\n"},
    {14, "14:Not found.\n"},
    {20, "20:Unknown client error.\n"},
    {21, "21:Unrecognized command.\n"},
    {22, "22:Missing parameter.\n"},
    {23, "23:Invalid format.\n"},
    {24, "24:Resource already exists.\n"},
    {99, "99:Not implemented.\n"},
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

int client_reply(int reply_code)
{
    printf("%s\n", reply_codes[get_reply(reply_code)].message);
    return reply_code;
}

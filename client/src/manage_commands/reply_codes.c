/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** reply_codes
*/

#include "reply_codes.h"

const reply_code_t reply_codes[] = {
    {00, "00:Success"},
    {01, "01:Service ready for new user."},
    {10, "10:Internal server error."},
    {11, "11:Server is full."},
    {12, "12:Too many requests."},
    {13, "13:Forbidden."},
    {14, "14:Not found."},
    {20, "20:Unknown client error."},
    {21, "21:Unrecognized command."},
    {22, "22:Missing parameter."},
    {23, "23:Invalid format."},
    {24, "24:Resource already exists."},
    {99, "99:Not implemented."},
};

int get_reply(int code)
{
    int i = 0;

    for (; reply_codes[i].code != 0; i++)
        if (reply_codes[i].code == code)
            return i;
    return i;
}

//printf("%s\n", reply_codes[get_reply(reply_code)].message);
int client_reply(int reply_code)
{
    return reply_code;
}

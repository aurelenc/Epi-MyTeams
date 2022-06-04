/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** print_message
*/

#include "get_command.h"
#include "reply_codes.h"
#include "logging_client.h"

int print_message(char **tab_res, int reply_code)
{
    if (reply_code == GET_REPLY)
        client_event_thread_reply_received(tab_res[1], tab_res[3], tab_res[5],
        tab_res[7]);
    if (reply_code == GET_TEAM)
        client_event_team_created(tab_res[1], tab_res[3], tab_res[5]);
    if (reply_code == GET_CHANNEL)
        client_event_channel_created(tab_res[1], tab_res[3], tab_res[5]);
    if (reply_code == GET_THREAD)
        client_event_thread_created(tab_res[1], tab_res[3], atol(tab_res[5]),
        tab_res[7], tab_res[9]);
    if (reply_code == GET_MESSAGE)
        client_event_private_message_received(tab_res[1], tab_res[2]);
    return 0;
}

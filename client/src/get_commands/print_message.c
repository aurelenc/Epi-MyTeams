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
// char const *team_uuid,
// char const *thread_uuid,
// char const *user_uuid,
// char const *reply_body);
    if (reply_code == GET_TEAM)
        client_event_team_created(tab_res[1], tab_res[3], tab_res[5]);
// char const *team_uuid,
// char const *team_name,
// char const *team_description);
    if (reply_code == GET_CHANNEL)
        client_event_channel_created(tab_res[1], tab_res[3], tab_res[5]);
// char const *channel_uuid,
// char const *channel_name,
// char const *channel_description);
    if (reply_code == GET_THREAD)
        client_event_thread_created(tab_res[1], tab_res[3], atol(tab_res[5]),
        tab_res[7], tab_res[9]);
// char const *thread_uuid,
// char const *user_uuid,
// time_t thread_timestamp,
// char const *thread_title,
// char const *thread_body);
    if (reply_code == GET_MESSAGE)
        client_event_private_message_received(tab_res[1], tab_res[2]);
//    char const *user_uuid,
//    char const *message_body);
    return 0;
}

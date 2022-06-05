/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** info_thread
*/

#include "reply_codes.h"
#include "server.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tables/users/database_users_search.h"

static char *get_msg_reply(thread_t *thread, client_sock_t *clients, TEAMS_A)
{
    char *buff = calloc(sizeof(char), MAX_BUFF_SIZE + 1);

    snprintf(buff, MAX_BUFF_SIZE, "[\"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"]",
    thread->uuid, db_search_user_by_id(THIS_DB, thread->user_id)->uuid,
    thread->timestamp, thread->title, thread->body);
    printf("%s\n", buff);
    return (buff);
}

int command_info_thread(TEAMS_A)
{
    char *message = get_msg_reply(THIS_CLIENT.thread, TEAMS_CLIENTS, param);

    client_reply(PARAM_CID, PRINT_ALL_THREADS, message);
    free(message);
    return SUCCESS;
}

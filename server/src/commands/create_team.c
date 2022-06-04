/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** create_team
*/

#include "reply_codes.h"
#include "server.h"
#include "tables/channels/database_channels_add.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *get_success(team_t *team)
{
    int len = strlen(team->uuid) + strlen(team->name) +
    strlen(team->desc) + 16;
    char *buff = calloc(sizeof(char), len);

    snprintf(buff, len, "50:[ \"%s\" \"%s\" \"%s\"]\n", team->uuid, team->name,
    team->desc);
    printf("%s\n", buff);
    return (buff);
}

static team_t *create_team(TEAMS_A)
{
    team_t *team = 0;

    team = team_init(THIS_ARG[1], THIS_ARG[2]);
    server_event_team_created(team->uuid, team->name, THIS_CLIENT.user->uuid);
    db_add_team(THIS_DB, team);
    return team;
}

int command_create_team(TEAMS_A)
{
    char *buff = 0;
    int retval = 0;

    if (param->arg.nb < 3) {
        return client_reply(param->clients, param->id, MISSING_PARAMETER);
    } else if (param->arg.nb > 3) {
        return client_reply(param->clients, param->id, INVALID_FORMAT);
    }
    buff = get_success(create_team(param));
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (TEAMS_CLIENTS[i].socket != 0 && TEAMS_CLIENTS[i].user)
            client_reply_success(param->clients, i, buff);
    }
    free(buff);
    return 50;
}

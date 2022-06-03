/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** command_head
*/

#ifndef COMMAND_HEAD_H_
#define COMMAND_HEAD_H_

#define COMMAND_HEAD(log_name, min_args, max_args)\
    char *success_buff = 0;\
    user_t *found = 0;\
\
    printf("[SERVER] %s\n", log_name);\
    if (param->arg.nb < min_args) {\
        return client_reply(TEAMS_CLIENTS, param->id, MISSING_PARAMETER);\
    } else if (param->arg.nb > max_args) {\
        return client_reply(TEAMS_CLIENTS, param->id, INVALID_FORMAT);\
    }\
    if (!THIS_CLIENT.user)\
        return client_reply(PARAM_CID, FORBIDDEN);

#endif /* !COMMAND_HEAD_H_ */

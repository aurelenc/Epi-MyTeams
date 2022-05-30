/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** reply_codes
*/

#ifndef REPLY_CODES_H_
#define REPLY_CODES_H_

#include "client.h"

/// @brief Reply codes structure
typedef struct reply_code_s {
    int code;
    char *message;
} reply_code_t;

/// @brief Reply codes array
extern const reply_code_t reply_codes[];

int client_reply(int reply_code);

#define SUCCESS 00
#define SERVICE_READY_FOR_NEW_USER 01
#define INTERNAL_SERVER_ERROR 10
#define SERVER_IS_FULL 11
#define TOO_MANY_REQUESTS 12
#define FORBIDDEN 13
#define NOT_FOUND 14
#define UNKNOWN_CLIENT_ERROR 20
#define UNRECOGNIZED_COMMAND 21
#define MISSING_PARAMETER 22
#define INVALID_FORMAT 23
#define RESOURCE_ALREADY_EXISTS 24

#define NOT_IMPLEMENTED 99

#endif /* !REPLY_CODES_H_ */

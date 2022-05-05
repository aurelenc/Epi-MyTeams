/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database
*/

#pragma once

#include "user.h"
#include "team.h"

typedef struct channels_s {
    id_t id;
    char *name;
    id_t team_id;
} channels_t;

typedef struct msg_s
{
    id_t id;
    char *content;
    id_t user_id;
    id_t thread_id;
    id_t channel_id;
    id_t discussion_id;
} msg_t;

typedef struct thread_s {
    id_t id;
    id_t start_msg_id;
} thread_t;

typedef struct discussion_s {
    id_t id;
    char *name;
    id_t user_one_id;
    id_t user_txo_id;
} discussion_t;

typedef struct database_s
{

} database_t;

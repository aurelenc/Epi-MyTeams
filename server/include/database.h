/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database
*/

#pragma once

typedef unsigned int id_t;

typedef struct user_s {
    id_t id;
    char *pseudo;
    char *password;
} user_t ;

typedef struct team_s {
    id_t id;
    char *name;
} team_t;

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

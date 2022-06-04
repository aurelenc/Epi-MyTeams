/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** server_db_loading
*/

#include "logging_server.h"
#include "server.h"
#include "database_management.h"

void load_server_db(server_t *server)
{
    node_t *ptr = 0;
    user_t *user = 0;

    db_load(server->db);
    ptr = server->db->users->first;
    while (ptr) {
        user = (user_t *)ptr->data;
        server_event_user_loaded(user->uuid, user->pseudo);
        ptr = ptr->next;
    }
}

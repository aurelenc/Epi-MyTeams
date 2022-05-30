/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database_channels_multiple_search
*/

#include "channel.h"
#include "database.h"
#include "database_management.h"
#include "channel_search.h"

database_t *db_multiple_search_channel_by_team_id(database_t *db,
const id_t team_id)
{
    database_t *found = db_creation();

    if (!found)
        return (0);
    llist_destruction(found->channels);
    found->channels = llist_multiple_search(db->channels, &channel_team_id_compare, &team_id);
    return found;
}

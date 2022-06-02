/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_load_channels
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "llist.h"
#include "database_management.h"
#include "tables/channels/channel.h"
#include "tables/channels/database_channels_save.h"
#include <stdio.h>

Test (load_a_basic_db, db_load_channels)
{
    database_t *db = db_creation();
    channel_t *chan = 0;

    cr_assert_eq(db_load_channels(db, "tests/test_files/channels_load.csv"), true);
    chan = (channel_t *)db->channels->first->data;
    cr_assert_eq(chan->id, 1);
    cr_assert_str_eq(chan->name, "name");
    chan = (channel_t *)db->channels->first->next->data;
    cr_assert_eq(chan->id, 2);
    cr_assert_str_eq(chan->uuid, "2uuid");
    chan = (channel_t *)db->channels->first->next->next->data;
    cr_assert_eq(chan->id, 3);
    cr_assert_str_eq(chan->desc, "ds30SC");
}

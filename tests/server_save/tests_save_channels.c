/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_save_channels
*/

#include <criterion/criterion.h>
#include "save.h"
#include "llist.h"
#include "database_management.h"
#include "tables/channels/channel.h"
#include "tables/channels/database_channels_save.h"
#include <stdio.h>

Test (save_a_basic_db, save_channels)
{
    database_t *db = db_creation();
    channel_t *channel = 0;

    channel = channel_init(1, "name", "desc1", 10);
    channel->uuid = strdup("UUID1");
    llist_append(db->channels, channel);
    channel = channel_init(2, "forname", "2DESC", 20);
    channel->uuid = strdup("2uuid");
    llist_append(db->channels, channel);

    cr_assert_eq(save_channels(db, "tests/test_files/channels.csv"), true);
    cr_assert_str_eq(get_file_content("tests/test_files/channels.csv"), "\"1\";\"UUID1\";\"name\";\"desc1\";\"10\";\n\"2\";\"2uuid\";\"forname\";\"2DESC\";\"20\";\n");
}
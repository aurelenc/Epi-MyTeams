/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_save_messages
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "llist.h"
#include "database_management.h"
#include "tables/messages/message.h"
#include "tables/messages/database_messages_save.h"
#include <stdio.h>

Test (save_a_basic_db, db_save_messages)
{
    database_t *db = db_creation();
    msg_t *msg = 0;
    int *rel = calloc(sizeof(int), 2);

    rel[0] = 100;
    rel[1] = 1000;
    msg = msg_init(1,"content1", 10, rel);
    msg->uuid = strdup("UUID1");
    msg->timestamp = 123456789;
    llist_append(db->messages, msg);
    rel[0] = 200;
    rel[1] = 2000;
    msg = msg_init(2,"CONT\nent", 20, rel);
    msg->uuid = strdup("2uuid");
    msg->timestamp = 987654321;
    llist_append(db->messages, msg);

    cr_assert_eq(db_save_msg(db, "tests/test_files/messages.csv"), true);
    cr_assert_str_eq(get_file_content("tests/test_files/messages.csv"), "\"1\";\"UUID1\";\"content1\";\"123456789\";\"10\";\"100\";\"1000\";\n\"2\";\"2uuid\";\"CONT\nent\";\"987654321\";\"20\";\"200\";\"2000\";\n");
    db_destruction(db);
}

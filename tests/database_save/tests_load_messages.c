/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_load_msg
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "database_management.h"
#include "tables/messages/message.h"
#include "tables/messages/database_messages_save.h"
#include <stdio.h>

Test (load_a_basic_db, db_load_msg)
{
    database_t *db = db_creation();
    msg_t *msg = 0;

    cr_assert_eq(db_load_msg(db, "tests/test_files/messages_load.csv"), true);
    msg = (msg_t *)db->messages->first->data;
    cr_assert_eq(msg->id, 1);
    cr_assert_str_eq(msg->uuid, "UUID1");
    msg = (msg_t *)db->messages->first->next->data;
    cr_assert_eq(msg->id, 2);
    cr_assert_eq(msg->timestamp, 987654321);
    msg = (msg_t *)db->messages->first->next->next->data;
    cr_assert_eq(msg->id, 3);
    cr_assert_str_eq(msg->content, "cont\nENT");
    db_destruction(db);
}

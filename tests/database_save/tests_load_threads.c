/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_load_threads
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "database_management.h"
#include "tables/threads/thread.h"
#include "tables/threads/database_threads_save.h"
#include <stdio.h>

Test (load_a_basic_db, db_load_threads)
{
    database_t *db = db_creation();
    thread_t *thread = 0;

    cr_assert_eq(db_load_threads(db, "tests/test_files/threads_load.csv"), true);
    thread = (thread_t *)db->threads->first->data;
    cr_assert_eq(thread->id, 1);
    cr_assert_str_eq(thread->uuid, "UUID1");
    thread = (thread_t *)db->threads->first->next->data;
    cr_assert_eq(thread->id, 2);
    cr_assert_str_eq(thread->body, "DESC2");
    thread = (thread_t *)db->threads->first->next->next->data;
    cr_assert_eq(thread->id, 3);
    cr_assert_eq(thread->timestamp, 567891234);
    db_destruction(db);
}

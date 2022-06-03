/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** tests_db_save_threads
*/

#include <criterion/criterion.h>
#include "tables/load_functions.h"
#include "llist.h"
#include "database_management.h"
#include "tables/threads/thread.h"
#include "tables/threads/database_threads_save.h"
#include <stdio.h>

Test (save_a_basic_db, db_save_threads)
{
    database_t *db = db_creation();
    thread_t *thread = 0;

    thread = thread_init(1, "10", "100", 1000);
    thread->uuid = strdup("UUID1");
    thread->timestamp = 123456789;
    llist_append(db->threads, thread);
    thread = thread_init(2, "20", "200", 2000);
    thread->uuid = strdup("2uuid");
    thread->timestamp = 987654321;
    llist_append(db->threads, thread);

    cr_assert_eq(db_save_threads(db, "tests/test_files/threads.csv"), true);
    cr_assert_str_eq(get_file_content("tests/test_files/threads.csv"), "\"1\";\"UUID1\";\"10\";\"100\";\"1000\";\"123456789\";\n\"2\";\"2uuid\";\"20\";\"200\";\"2000\";\"987654321\";\n");
    db_destruction(db);
}

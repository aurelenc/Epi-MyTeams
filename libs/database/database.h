/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** database
*/

#pragma once

#include "tables/user.h"
#include "tables/team.h"
#include "tables/channel.h"
#include "tables/message.h"
#include "tables/thread.h"
#include "tables/discussion.h"
#include "llist.h"
#include "search/database_search_functions.h"

typedef struct database_s
{
    llist_t *users;
    llist_t *teams;
    llist_t *channels;
    llist_t *messages;
    llist_t *threads;
    llist_t *discussions;
    llist_t *users_teams;
} database_t;

///
/// @brief It creates a database
///
/// @return A pointer to a database_t struct.
///
database_t *db_creation(void);

///
/// @brief It frees all the linked lists in the database
///
/// @param database the database to destroy
///
/// @return A pointer to a database_t struct.
///
database_t *db_destruction(database_t *database);

/*
** Users
*/

///
/// @brief Add a user to the database.
///
/// @param db The database to add the user to.
/// @param user The user to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_user(database_t *db, user_t *user)
{
    return llist_append(db->users, user);
};

///
/// @brief It searches the database for a user with the given id
///
/// @param db The database to search in.
/// @param id The id of the user to search for.
///
/// @return A pointer to a user_t struct.
///
static inline user_t *db_search_user_by_id(database_t *db, const id_t id)
{
    return (user_t *)llist_search(db->users, &user_id_compare, &id);
};

///
/// @brief It searches the database for a user with the given pseudo
///
/// @param db the database
/// @param pseudo the pseudo of the user to search for
///
/// @return A pointer to the user_t struct.
///
static inline user_t *db_search_user_by_pseudo(database_t *db,
const char *pseudo)
{
    return (user_t *)llist_search(db->users, &user_pseudo_compare, pseudo);
};

///
/// @brief It deletes a user, with the given id, in the database
///
/// @param db The database to search in.
/// @param id The id of the user to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_user_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->users, &user_id_compare, &id);
}

///
/// @brief It deletes a user, with the given pseudo, in the database
///
/// @param db the database.
/// @param pseudo the pseudo of the user to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_user_by_pseudo(database_t *db,
const char *pseudo)
{
    return llist_delif(db->users, &user_pseudo_compare, pseudo);
}

/*
** Team
*/

///
/// @brief It adds a team to the database
///
/// @param db The database to add the team to.
/// @param team The team to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_team(database_t *db, team_t *team)
{
    return llist_append(db->teams, team);
};

///
/// @brief It searches the database for a team with the given id
///
/// @param db The database to search in.
/// @param id The id of the team to search for.
///
/// @return A pointer to a team_t struct.
///

static inline team_t *db_search_team_by_id(database_t *db, const id_t id)
{
    return (team_t *)llist_search(db->teams, &team_id_compare, &id);
};

///
/// @brief It searches the database for a team with the given name
///
/// @param db The database to search in.
/// @param name The name of the team to search for.
///
/// @return A pointer to a team_t struct.
///
static inline team_t *db_search_team_by_name(database_t *db, const char *name)
{
    return (team_t *)llist_search(db->teams, &team_name_compare, name);
};

///
/// @brief It deletes a team from the database by its id
///
/// @param db The database to delete the team from.
/// @param id The id of the team to delete
///
/// @return A boolean value.
///
static inline bool db_delete_team_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->teams, &team_id_compare, &id);
}

///
/// @brief It deletes the first team in the database whose name matches the
/// given name
///
/// @param db The database to search in.
/// @param name The name of the team to search for.
///
/// @return A boolean value.
///
static inline bool db_delete_team_by_name(database_t *db, const char *name)
{
    return llist_delif(db->teams, &team_name_compare, name);
}

/*
** Channel
*/

///
/// @brief It adds a channel to the database
///
/// @param db The database object
/// @param channel The channel to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_channel(database_t *db, channel_t *channel)
{
    return llist_append(db->channels, channel);
};

///
/// @brief It searches the database for a channel with the given id
///
/// @param db The database to search in.
/// @param id The id of the channel to search for.
///
/// @return A pointer to a channel_t struct.
///
static inline channel_t *db_search_channel_by_id(database_t *db, const id_t id)
{
    return (channel_t *)llist_search(db->channels, &channel_id_compare, &id);
};

///
/// @brief It searches the database for a channel with the given name
///
/// @param db The database to search in.
/// @param name The name of the channel to search for.
///
/// @return A pointer to a channel_t struct.
///
static inline channel_t *db_search_channel_by_name(database_t *db,
const char *name)
{
    return (channel_t *)llist_search(db->channels, &channel_name_compare, name);
};

///
/// @brief It searches the database's
///channel list for a channel with the given team ID
///
/// @param db The database to search in.
/// @param team_id The team ID to search for.
///
/// @return A pointer to a channel_t struct.
///
static inline channel_t *db_search_channel_by_team_id(database_t *db,
const id_t team_id)
{
    return (channel_t *)llist_search(db->channels, &channel_team_id_compare,
    &team_id);
};

///
/// @brief It deletes a channel from the database by its id
///
/// @param db The database to delete the channel from.
/// @param id The id of the channel to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_channel_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->channels, &channel_id_compare, &id);
}

///
/// @brief It deletes a channel from the database by name
///
/// @param db The database to delete the channel from.
/// @param name The name of the channel to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_channel_by_name(database_t *db,
const char *name)
{
    return llist_delif(db->channels, &channel_name_compare, name);
}

///
/// @brief It deletes a channel from the database if it has the same team id as
/// the one passed in
///
/// @param db The database to delete the channel from.
/// @param team_id The id of the team to delete the channel of.
///
/// @return A boolean value.
///
static inline bool db_delete_channel_by_team_id(database_t *db,
const id_t team_id)
{
    return llist_delif(db->channels, &channel_team_id_compare, &team_id);
};

/*
** Message
*/

///
/// @brief It adds a message to the database
///
/// @param db The database object
/// @param message The message to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_msg(database_t *db, msg_t *message)
{
    return llist_append(db->messages, message);
};

///
/// @brief It searches the database for a message with the given id
///
/// @param db The database to search in.
/// @param id The id of the message to search for.
///
/// @return A pointer to a msg_t struct.
///
static inline msg_t *db_search_msg_by_id(database_t *db, const id_t id)
{
    return (msg_t *)llist_search(db->messages, &msg_id_compare, &id);
};

///
/// @brief It searches the database's
/// message list for a message with the given user ID
///
/// @param db The database to search in.
/// @param user_id The user ID to search for.
///
/// @return A pointer to a msg_t struct.
///
static inline msg_t *db_search_msg_by_user_id(database_t *db,
const id_t user_id)
{
    return (msg_t *)llist_search(db->messages, &msg_user_id_compare, &user_id);
};

///
/// @brief It searches the database's
/// message list for a message with the given thread ID
///
/// @param db The database to search in.
/// @param thread_id The thread ID to search for.
///
/// @return A pointer to a msg_t struct.
///
static inline msg_t *db_search_msg_by_thread_id(database_t *db,
const id_t thread_id)
{
    return (msg_t *)llist_search(db->messages, &msg_thread_id_compare,
    &thread_id);
};

///
/// @brief It searches the database's
/// message list for a message with the given channel ID
///
/// @param db The database to search in.
/// @param channel_id The channel ID to search for.
///
/// @return A pointer to a msg_t struct.
///
static inline msg_t *db_search_msg_by_channel_id(database_t *db,
const id_t channel_id)
{
    return (msg_t *)llist_search(db->messages, &msg_channel_id_compare,
    &channel_id);
};

///
/// @brief It searches the database's
/// message list for a message with the given discussion ID
///
/// @param db The database to search in.
/// @param discu_id The discussion ID to search for.
///
/// @return A pointer to a msg_t struct.
///
static inline msg_t *db_search_msg_by_discussion_id(database_t *db,
const id_t discu_id)
{
    return (msg_t *)llist_search(db->messages, &msg_discussion_id_compare,
    &discu_id);
};

///
/// @brief It deletes a message from the database by its id
///
/// @param db The database to delete the message from.
/// @param id The id of the message to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_msg_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->messages, &msg_id_compare, &id);
}

///
/// @brief It deletes a message from the database if it has the same user id as
/// the one passed in
///
/// @param db The database to delete the message from.
/// @param user_id The id of the user to delete the message of.
///
/// @return A boolean value.
///
static inline bool db_delete_msg_by_user_id(database_t *db,
const id_t user_id)
{
    return llist_delif(db->messages, &msg_user_id_compare, &user_id);
};

///
/// @brief It deletes a message from the database if it has the same thread id
/// as the one passed in
///
/// @param db The database to delete the message from.
/// @param thread_id The id of the thread to delete the message of.
///
/// @return A boolean value.
///
static inline bool db_delete_msg_by_thread_id(database_t *db,
const id_t thread_id)
{
    return llist_delif(db->messages, &msg_thread_id_compare, &thread_id);
};

///
/// @brief It deletes a message from the database if it has the same channel id
// as the one passed in
///
/// @param db The database to delete the message from.
/// @param channel_id The id of the channel to delete the message of.
///
/// @return A boolean value.
///
static inline bool db_delete_msg_by_channel_id(database_t *db,
const id_t channel_id)
{
    return llist_delif(db->messages, &msg_channel_id_compare, &channel_id);
};

///
/// @brief It deletes a message from the database if it has the same discussion
/// id as the one passed in
///
/// @param db The database to delete the message from.
/// @param discu_id The id of the discussion to delete the message of.
///
/// @return A boolean value.
///
static inline bool db_delete_msg_by_discussion_id(database_t *db,
const id_t discu_id)
{
    return llist_delif(db->messages, &msg_discussion_id_compare, &discu_id);
};

/*
** Thread
*/

///
/// @brief It adds a thread to the database
///
/// @param db The database object
/// @param thread The thread to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_thread(database_t *db, thread_t *thread)
{
    return llist_append(db->threads, thread);
};

///
/// @brief It searches the database for a thread with the given id
///
/// @param db The database to search in.
/// @param id The id of the thread to search for.
///
/// @return A pointer to a thread_t struct.
///
static inline thread_t *db_search_thread_by_id(database_t *db, const id_t id)
{
    return (thread_t *)llist_search(db->threads, &thread_id_compare, &id);
};

///
/// @brief It searches the database's
///thread list for a thread with the given start message ID
///
/// @param db The database to search in.
/// @param start_msg_id The start message ID to search for.
///
/// @return A pointer to a thread_t struct.
///
static inline thread_t *db_search_thread_by_start_msg_id(database_t *db,
const id_t start_msg_id)
{
    return (thread_t *)llist_search(db->threads, &thread_start_msg_id_compare,
    &start_msg_id);
};

///
/// @brief It deletes a thread from the database by its id
///
/// @param db The database to delete the thread from.
/// @param id The id of the thread to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_thread_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->threads, &thread_id_compare, &id);
}

///
/// @brief It deletes a thread from the database if it has the same start
/// message id as the one passed in
///
/// @param db The database to delete the thread from.
/// @param start_msg_id The id of the start message to delete the thread of.
///
/// @return A boolean value.
///
static inline bool db_delete_thread_by_start_msg_id(database_t *db,
const id_t start_msg_id)
{
    return llist_delif(db->threads, &thread_start_msg_id_compare,
    &start_msg_id);
};

/*
** Discussion
*/

///
/// @brief It adds a discussion to the database
///
/// @param db The database object
/// @param discussion The discussion to add to the database.
///
/// @return A boolean value.
///
static inline bool db_add_discussion(database_t *db, discussion_t *discussion)
{
    return llist_append(db->discussions, discussion);
};

///
/// @brief It searches the database for a discussion with the given id
///
/// @param db The database to search in.
/// @param id The id of the discussion to search for.
///
/// @return A pointer to a discussion_t struct.
///
static inline discussion_t *db_search_discussion_by_id(database_t *db,
const id_t id)
{
    return (discussion_t *)llist_search(db->discussions,
    &discussion_id_compare, &id);
};

///
/// @brief It searches the database for a discussion with the given name
///
/// @param db The database to search in.
/// @param name The name of the discussion to search for.
///
/// @return A pointer to a discussion_t struct.
///
static inline discussion_t *db_search_discussion_by_name(database_t *db,
const char *name)
{
    return (discussion_t *)llist_search(db->discussions,
    &discussion_name_compare, name);
};

///
/// @brief It searches the database's
///discussion list for a discussion with the given user one ID
///
/// @param db The database to search in.
/// @param user_one_id The user one ID to search for.
///
/// @return A pointer to a discussion_t struct.
///
static inline discussion_t *db_search_discussion_by_user_one_id(database_t *db,
const id_t user_one_id)
{
    return (discussion_t *)llist_search(db->discussions,
    &discussion_user_one_id_compare, &user_one_id);
};

///
/// @brief It searches the database's
/// discussion list for a discussion with the given user two ID
///
/// @param db The database to search in.
/// @param user_two_id The user two ID to search for.
///
/// @return A pointer to a discussion_t struct.
///
static inline discussion_t *db_search_discussion_by_user_two_id(database_t *db,
const id_t user_two_id)
{
    return (discussion_t *)llist_search(db->discussions,
    &discussion_user_two_id_compare, &user_two_id);
};

///
/// @brief It deletes a discussion from the database by its id
///
/// @param db The database to delete the discussion from.
/// @param id The id of the discussion to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_discussion_by_id(database_t *db, const id_t id)
{
    return llist_delif(db->discussions, &discussion_id_compare, &id);
};

///
/// @brief It deletes a discussion from the database by name
///
/// @param db The database to delete the discussion from.
/// @param name The name of the discussion to delete.
///
/// @return A boolean value.
///
static inline bool db_delete_discussion_by_name(database_t *db,
const char *name)
{
    return llist_delif(db->discussions, &discussion_name_compare, name);
};

///
/// @brief It deletes a discussion from the database if it has the same user one
/// id as the one passed in
///
/// @param db The database to delete the discussion from.
/// @param user_one_id The id of the user one to delete the discussion of.
///
/// @return A boolean value.
///
static inline bool db_delete_discussion_by_user_one_id(database_t *db,
const id_t user_one_id)
{
    return llist_delif(db->discussions, &discussion_user_one_id_compare,
    &user_one_id);
};

///
/// @brief It deletes a discussion from the database if it has the same user two
/// id as the two passed in
///
/// @param db The database to delete the discussion from.
/// @param user_two_id The id of the user two to delete the discussion of.
///
/// @return A boolean value.
///
static inline bool db_delete_discussion_by_user_two_id(database_t *db,
const id_t user_two_id)
{
    return llist_delif(db->discussions, &discussion_user_two_id_compare,
    &user_two_id);
};

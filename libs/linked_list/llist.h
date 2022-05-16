/*
** EPITECH PROJECT, 2022
** Linked List Library
** File description:
** llist
*/

#pragma once

#include <stdbool.h>

typedef struct node_s
{
    void *data;
    struct node_s *next;
} node_t;

typedef struct llist_s
{
    node_t *first;
} llist_t;

/*
** Functions
*/

/**
 * @brief Defining a function pointer whose purpose is to compare two given
 * parameters
 */
typedef bool (*data_search_t)(const void *elem, const void *search);

/**
 * @brief Define a function pointer which have to purpose to display data.
 */
typedef void (*data_displayer_t)(const void *data);

/* Initialization */

/**
 * @brief It creates a new linked list and returns a pointer to it
 *
 * @return A pointer to a new linked list.
 */
llist_t *llist_init(void);

/* Informations */

/**
 * @brief Get the size of the list.
 *
 * @param list The list to get the size of.
 *
 * @return The number of nodes in the list.
 */
unsigned int llist_get_size(llist_t *list);

/**
 * @brief Return true if the list is empty, false otherwise.
 *
 * @param list The list to check.
 *
 * @return The size of the list.
 */
bool llist_is_empty(llist_t *list);

/**
 * @brief It displays the contents of the list
 *
 * @param list the list to dump
 * @param val_disp a function pointer to a function that takes a void pointer
 * and displays the data it points to.
 *
 * @return A pointer to the first node in the list.
 */
void llist_dump(llist_t *list, data_displayer_t val_disp);

/* Modification */

/**
 * @brief It creates a new node,
 * sets its data to the given element, sets its next pointer to the current
 * first node, and then sets the list's first pointer to the new node
 *
 * @param list the list to push the element to
 * @param elem the element to add to the list
 *
 * @return A boolean value.
 */
bool llist_push_front(llist_t *list, void *elem);

/**
 * @brief Append an element to the end of the list.
 *
 * @param list A pointer to the list to append to.
 * @param elem The element to be added to the list.
 *
 * @return A pointer to the first node in the list.
 */
bool llist_append(llist_t *list, void *elem);

/**
 * @brief It creates a new node,
 * inserts it into the list at the given position, and returns true if it
 * succeeds
 *
 * @param list the list to insert the element into
 * @param elem the element to insert
 * @param position the position where you want to insert the element.
 *
 * @return A pointer to the node at the given position.
 */
bool llist_insert(llist_t *list, void *elem, unsigned int position);


/**
 * @brief If the list is not empty,
 * remove the first node from the list and free it
 *
 * @param list The list to pop the front of.
 *
 * @return A boolean value.
 */
bool llist_pop_front(llist_t *list);

/**
 * @brief If the list is not empty,
 * then free the last node in the list.
 *
 * @param list The list to pop the back of.
 *
 * @return a boolean value.
 */
bool llist_pop_back(llist_t *list);

/**
 * @brief It deletes the node at the given position by taking the node at the
 * previous position, and setting its next pointer to the next pointer of the
 * node at the given position
 *
 * @param list The list to delete from.
 * @param position The position of the node to delete.
 *
 * @return A boolean value.
 */
bool llist_delete_at(llist_t *list, unsigned int position);

bool llist_delif(llist_t *list, data_search_t search_fun, void *search);

/**
 * @brief Clear the entire list.
 *
 * @param list The list to clear.
 */
void llist_clear(llist_t *list);

/* Value Access */

/**
 * @brief Return the first element of the list, or 0 if the list is empty.
 *
 * @param list A pointer to the list.
 *
 * @return The first element of the list.
 */
void *llist_front(llist_t *list);

/**
 * @brief Return the last element of the list.
 *
 * @param list The list to get the last element from.
 *
 * @return The last element of the list.
 */
void *llist_back(llist_t *list);

/**
 * @brief It takes a node from the list at the given position, and returns the
 * data from that node
 *
 * @param list The list to get the data from.
 * @param position The position of the node to get.
 *
 * @return The data of the node at the given position.
 */
void *llist_get(llist_t *list, unsigned int position);

/**
 * @brief It searches for a data in the list that matches the search criteria
 *
 * @param list the list to search
 * @param search_fun a function that takes two void pointers as parameters and
 * returns an bool.
 * @param search the data to search for
 *
 * @return The data of the node that matches the search criteria.
 */
void *llist_search(llist_t *list, data_search_t search_fun, void *search);

/* List destruction */

/**
 * @brief It clears the list and frees the memory.
 *
 * @param list The list to be cleared.
 *
 * @return a pointer to the list.
 */
llist_t *llist_destruction(llist_t *list);

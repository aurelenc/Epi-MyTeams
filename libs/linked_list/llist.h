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

/* Informations */

unsigned int llist_get_size(llist_t *list);
bool llist_is_empty(llist_t *list);

typedef void (*data_displayer_t)(const void *data);

void llist_dump(llist_t *list, data_displayer_t val_disp);

/* Modification */

bool llist_push_front(llist_t *list, void *elem);
bool llist_append(llist_t *list, void *elem);
bool llist_insert(llist_t *list, void *elem, unsigned int position);

bool llist_pop_front(llist_t *list);
bool llist_pop_back(llist_t *list);
bool llist_delete_at(llist_t *list, unsigned int position);

void llist_clear(llist_t *list);

/* Value Access */

void *llist_front(llist_t *list);
void *llist_back(llist_t *list);
void *llist_get(llist_t *list, unsigned int position);

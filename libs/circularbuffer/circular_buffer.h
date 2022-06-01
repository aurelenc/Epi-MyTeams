/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** circular_buffer
*/

#pragma once

#include <stdbool.h>

#define CIRCULAR_BUFFER_SIZE 4e+6

#define CIRCULAR_BUFFER calloc(sizeof(char), CIRCULAR_BUFFER_SIZE)

// /**
// ** @struct cbuff_s
// ** @brief The circular buffer structure
// ** @var input contains the input buffer of size BUFFER_SIZE
// ** @var output contains the output buffer of size BUFFER_SIZE
// **/
// typedef struct cbuff_s {
//     char input[CIRCULAR_BUFFER_SIZE];
//     char output[CIRCULAR_BUFFER_SIZE];
// } cbuff_t;

typedef enum cbuff_ret_e {
    BUFFER_OK,
    BUFFER_FULL,
    BUFFER_NO_DATA,
    ENUM_CBUFF_RET_SIZE
} cbuff_ret_t;

/**
** @brief Pushes a string into a circular buffer
** @param cbuff The circular buffer to push the string into
** @param src the string to push in the circular buffer
** @retval BUFFER_OK if the string was successfully pushed
** @retval BUFFER_FULL if the string is too big to be pushed into the buffer
**/
cbuff_ret_t cbuff_push(char *cbuff, char *src);

/**
** @brief Pushes a string into a circular buffer
** @param cbuff The circular buffer to pop the string from
** @param dest the string to push the next data into
** @param dest_len the length of the 'dest' string
** @retval BUFFER_OK if the string was successfully pulled
** @retval BUFFER_NO_DATA buffer does not contains any relevant data to pop into dest
**/
cbuff_ret_t cbuff_pop(char *cbuff, char *dest, size_t dest_size);

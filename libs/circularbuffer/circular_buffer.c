/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** circular_buffer
*/

#include <string.h>
#include <unistd.h>
#include "circular_buffer.h"

cbuff_ret_t cbuff_push(char *cbuff, char *src)
{
    size_t len = strlen(cbuff);

    if (len + strlen(src) > BUFFER_SIZE)
        return BUFFER_FULL;
    strcat(cbuff, src);
    return BUFFER_OK;
}

cbuff_ret_t cbuff_pop(char *cbuff, char *dest, size_t dest_len)
{
    char *buff_end = strchr(cbuff, '\n');
    size_t len;
    size_t size;

    if (!buff_end)
        return BUFFER_NO_DATA;
    len = strlen(cbuff);
    size = buff_end + 1 - cbuff;
    memset(dest, 0, size + 1);
    memcpy(dest, cbuff, dest_len);
    memmove(cbuff, size + cbuff, len);
    memset(cbuff + (len - size), 0, len - size);
    return BUFFER_OK;
}

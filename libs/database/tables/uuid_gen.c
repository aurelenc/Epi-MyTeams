/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** uuid_gen
*/

#include <uuid/uuid.h>
#include <stdlib.h>

char *uuid_gen(void)
{
    uuid_t binuuid;
    char *uuid = calloc(sizeof(char), 38);

    if (!uuid)
        return (NULL);
    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, uuid);
    return uuid;
}

/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** user
*/

#include "user.h"
#include "tables/uuid_gen.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

user_t *user_init(id_t id, const char *pseudo, const char *password)
{
    user_t *user = calloc(sizeof(user_t), 1);

    if (!user) {
        perror("User creation");
        exit (84);
    }
    user->id = id;
    user->uuid = uuid_gen();
    user->pseudo = strdup(pseudo);
    user->password = strdup(password);
    if (!user->uuid || !user->pseudo || ! user->password) {
        perror("User creation");
        exit (84);
    }
    return user;
}

void user_destruction(user_t *user)
{
    if (!user)
        return;
    free(user->password);
    free(user->pseudo);
    free(user);
}

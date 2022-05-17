/*
** EPITECH PROJECT, 2022
** Epi-MyTeams
** File description:
** reply_codes
*/

#ifndef REPLY_CODES_H_
#define REPLY_CODES_H_

/// @brief Reply codes structure
typedef struct reply_code_s {
    int code;
    char *message;
} reply_code_t;

/// @brief Reply codes array
extern const reply_code_t reply_codes[];

#define REPLY_SUCCESS 200
#define REPLY_SERVER_ERROR 500
#define REPLY_NOT_IMPLEMENTED 501

#endif /* !REPLY_CODES_H_ */

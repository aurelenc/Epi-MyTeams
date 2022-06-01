/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** save
*/

#pragma once

#include <stdlib.h>

///
/// @brief It reads the contents of a file into a string
///
/// @param filepath The path to the file you want to read.
///
/// @return A pointer to the first character of the file.
///
char *get_file_content(char *filepath);

///
/// It takes a string and a pointer to a size_t, and returns a string
///
/// @param entity The string to parse.
/// @param cur the current position in the entity string
///
/// @return A pointer to a string.
///
char *get_arg(char *entity, size_t *cur);

///
/// @brief It takes a string and a number of arguments, and returns an array of
/// strings containing the arguments
///
/// @param buffer the string to parse
/// @param nb_args the number of arguments that an entity has.
///
/// @return An array of arrays of strings.
///
char ***get_entities(char *buffer, size_t nb_args);

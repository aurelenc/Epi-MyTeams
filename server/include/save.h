/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** save
*/

#pragma once

///
/// @brief It reads the contents of a file into a string
///
/// @param filepath The path to the file you want to read.
///
/// @return A pointer to the first character of the file.
///
char *get_file_content(char *filepath);

///
/// @brief It takes a string and returns a pointer to a new string containing
/// the first entity in the original string
///
/// @param buffer The buffer to parse.
///
/// @return A pointer to a string.
///
char *get_entity(char *buffer);

///
/// @brief It takes a string and returns a pointer to the first argument of the
/// string
///
/// @param entity The string to parse.
///
/// @return The argument of the entity.
///
char *get_arg(char *entity);

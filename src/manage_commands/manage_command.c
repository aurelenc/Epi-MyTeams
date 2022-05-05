/*
** EPITECH PROJECT, 2022
** Project
** File description:
** manage_command
*/

#include "../../include/command.h"

void test(void)
{
}

/**
 * @brief A table of commands that the server can execute. 
*/
tab_command_t tabCommand[22] =
    {
  	{"LOGI", &test},
    {"LOGO", &test},
    {"USRS", &test},
    {"USR", &test},
    {"SEND", &test},
    {"MSG", &test},
    {"SUB", &test},
    {"SUBT", &test},
    {"SUBU", &test},
    {"USUB", &test},
    {"USTE", &test},
    {"USCH", &test},
    {"USTH", &test},
    {"CRTE", &test},
    {"CRCH", &test},
    {"CRTH", &test},
    {"LSTE", &test},
    {"LSCH", &test},
    {"LSTH", &test},
    {"IFTE", &test},
    {"IFCH", &test},
    {"IFTH", &test},
    // {"PASS", &test},
    // {"TYPE", &test},
    // {"CWD", &test},
    // {"CDUP", &test},
    // {"QUIT", &test},
    // {"DELE", &test},
    // {"PWD", &test},
    // {"PASV", &test},
    // {"HELP", &test},
  	// {"NOOP", &test},
    // {"RETR", &test},
    // {"STOR", &test},
    // {"LIST", &test},
  	{NULL, NULL}
};



/**
 * @brief It executes the command that the user has entered
 * 
 * @param command the command to execute
 * @param av the arguments of the command
 */
void executeCmd(char *command, char *av)
{
    for (int i = 0; tabCommand[i].cmd != NULL; i++)
        if (!strcmp(tabCommand[i].cmd, command))
            tabCommand[i].function(av);
}

/**
 * @brief It takes a string, splits it into a command and arguments, and then executes the
 * command
 * 
 * @param input The input string from the client.
 * 
 * @return The return value is the number of bytes received.
 */
int parseCommand(char *input)
{
    char *cmdClient = strtok(input, "\r\n");
    char *command = NULL;
    char *arguments = NULL;

    while (cmdClient) {
        command = strsep(&cmdClient, " ");
        arguments = cmdClient;
        executeCmd(command, arguments);
        cmdClient = strtok(NULL, "\r\t");
    }
    return (0);
}
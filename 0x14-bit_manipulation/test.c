/*
 * File: my_env_builtins.c
 * Auth: Betty
 *       Charlie Coder
 */

#include "shell.h"

int my_shell_env(char **args, char __attribute__((__unused__)) **front);
int my_shell_setenv(char **args, char __attribute__((__unused__)) **front);
int my_shell_unsetenv(char **args, char __attribute__((__unused__)) **front);

/**
 * my_shell_env - Displays the current environment variables.
 * @args: An array of arguments provided to the shell.
 * @front: A double pointer pointing to the start of args.
 *
 * Return: On error - -1.
 *         On success - 0.
 *
 * Description: Displays each variable in the format 'variable'='value'.
 */
int my_shell_env(char **args, char __attribute__((__unused__)) **front)
{
	int idx;
	char newline = '\n';

	if (!environ)
		return (-1);

	for (idx = 0; environ[idx]; idx++)
	{
		write(STDOUT_FILENO, environ[idx], _strlen(environ[idx]));
		write(STDOUT_FILENO, &newline, 1);
	}

	(void)args;
	return (0);
}

/**
 * my_shell_setenv - Updates or Creates an environment variable.
 * @args: An array of arguments provided to the shell.
 * @front: A double pointer pointing to the start of args.
 *
 * Description: args[1] is the name of the new/existing variable.
 *              args[2] is the value to set the variable to.
 *
 * Return: On error - -1.
 *         On success - 0.
 */
int my_shell_setenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var = NULL, **new_environ, *new_value;
	size_t size;
	int idx;

	if (!args[0] || !args[1])
		return (create_error(args, -1));

	new_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_value)
		return (create_error(args, -1));
	_strcpy(new_value, args[0]);
	_strcat(new_value, "=");
	_strcat(new_value, args[1]);

	env_var = _getenv(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_value;
		return (0);
	}

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 2));
	if (!new_environ)
	{
		free(new_value);
		return (create_error(args, -1));
	}

	for (idx = 0; environ[idx]; idx++)
		new_environ[idx] = environ[idx];

	free(environ);
	environ = new_environ;
	environ[idx] = new_value;
	environ[idx + 1] = NULL;

	return (0);
}

/**
 * my_shell_unsetenv - Removes an environment variable.
 * @args: An array of arguments provided to the shell.
 * @front: A double pointer pointing to the start of args.
 *
 * Description: args[1] displays the variable to remove.
 *
 * Return: On error - -1.
 *         On success - 0.
 */
int my_shell_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var, **new_environ;
	size_t size;
	int idx, idx2;

	if (!args[0])
		return (create_error(args, -1));

	env_var = _getenv(args[0]);
	if (!env_var)
		return (0);

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * size);
	if (!new_environ)
		return (create_error(args, -1));

	for (idx = 0, idx2 = 0; environ[idx]; idx++)
	{
		if (*env_var == environ[idx])
		{
			free(*env_var);
			continue;
		}
		new_environ[idx2] = environ[idx];
		idx2++;
	}
	free(environ);
	environ = new_environ;
	environ[size - 1] = NULL;

	return (0);
}

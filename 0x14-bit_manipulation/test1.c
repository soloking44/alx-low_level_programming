/*
 * File: my_builtin.c
 * Auth: Asakwonye Collins
 *       Olajumoke Olagunju
 */

#include "my_shell.h"

int my_shellby_alias(char **args, char __attribute__((__unused__)) **front);
void set_my_alias(char *var_name, char *value);
void print_my_alias(alias_t *alias);

/**
 * my_shellby_alias - Custom built-in command that manages aliases.
 * @args: An array of arguments.
 * @front: Pointer to the start of the args array.
 *
 * Return: Returns -1 on error, 0 otherwise.
 */
int my_shellby_alias(char **args, char __attribute__((__unused__)) **front)
{
	alias_t *curent = my_aliases;
	int i, result = 0;
	char *value;

	if (!args[0])
	{
		while (current)
		{
			print_my_alias(current);
			current = current->next;
		}
		return (result);
	}
	for (i = 0; args[i]; i++)
	{
		current = my_aliases;
		value = _strchr(args[i], '=');
		if (!value)
		{
			while (current)
			{
				if (_strcmp(args[i], current->name) == 0)
				{
					print_my_alias(current);
					break;
				}
				current = current->next;
			}
			if (!current)
				result = create_error(args + i, 1);
		}
		else
			set_my_alias(args[i], value);
	}
	return (result);
}

/**
 * set_my_alias - Sets or creates an alias with given name and value.
 * @var_name: The name of the alias.
 * @value: The value for the alias. The initial character is a '='.
 */
void set_my_alias(char *var_name, char *value)
{
	alias_t *current = my_aliases;
	int length, j, k;
	char *new_value;

	*value = '\0';
	value++;
	length = _strlen(value) - _strspn(value, "'\"");
	new_value = malloc(sizeof(char) * (length + 1));
	if (!new_value)
		return;
	for (j = 0, k = 0; value[j]; j++)
	{
		if (value[j] != '\'' && value[j] != '"')
			new_value[k++] = value[j];
	}
	new_value[k] = '\0';
	while (current)
	{
		if (_strcmp(var_name, current->name) == 0)
		{
			free(current->value);
			current->value = new_value;
			break;
		}
		current = current->next;
	}
	if (!current)
		add_alias_end(&my_aliases, var_name, new_value);
}

/**
 * print_my_alias - displays alias in the format name='value'.
 * @alias: Pointer pointing to an alias.
 */
void print_my_alias(alias_t *alias)
{
	char *alias_string;
	int length = _strlen(alias->name) + _strlen(alias->value) + 4;

	alias_string = malloc(sizeof(char) * (length + 1));
	if (!alias_string)
		return;
	_strcpy(alias_string, alias->name);
	_strcat(alias_string, "='");
	_strcat(alias_string, alias->value);
	_strcat(alias_string, "'\n");

	write(STDOUT_FILENO, alias_string, length);
	free(alias_string);
}

/**
 * replace_my_aliases - Replaces matching aliases with their values in args.
 * @args: Pointer to a 2D array containing the arguments.
 *
 * Return: Returns a 2D pointer pointing to the modified arguments.
 */
char **replace_my_aliases(char **args)
{
	alias_t *current;
	int i;
	char *new_value;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (i = 0; args[i]; i++)
	{
		current = my_aliases;
		while (current)
		{
			if (_strcmp(args[i], current->name) == 0)
			{
				new_value = malloc(sizeof(char) * (_strlength(current->value) + 1));
				if (!new_value)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(new_value, current->value);
				free(args[i]);
				args[i] = new_value;
				i--;
				break;
			}
			current = current->next;
		}
	}

	return (args);
}

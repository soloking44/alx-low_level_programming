#include "main.h"

/**
 * read_textfile - custom function that slurp up a text file and
 * echo it to the POSIX standard output.
 * @filename: name of the file to be devoured
 * @letters: the numbers of letters it should read and print.
 *
 * Return: the real number of letters it could read and display.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *print_field;
	int file, read_file;

	if (!filename)
		return (0);

	/*Create the buffer print_field*/
	print_field = malloc(letters * sizeof(char));
	if (!print_field)
		return (0);

	/*Open the file*/
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	/*Read the file and save in buffer*/
	read_file = read(file, print_field, letters);
	/*Write as standard output*/
	write(STDOUT_FILENO, print_field, read_file);

	close(file);
	free(print_field);
	return (read_file);
}

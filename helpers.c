#include "shell.h"

/**
 * exec_cmd - This program creates a new child process
 * executes a command, and waits for the child process
 * to update its status
 * @c: command
 * @cmd: vector array of pointers to commands
 *
 * Return: void
 */

void exec_cmd(char *c, char **cmd)
{
	pid_t newProcess;
	int status;
	char **envp = environ;

	newProcess = fork();
	if (newProcess < 0)
		perror(c);
	if (newProcess == 0)
	{
		execve(c, cmd, envp);
		perror(c);
		free(c);
		free_cmds(cmd);
		exit(98);
	}
	else
	{
		wait(&status);
	}
}

/**
 * tokenize - splits a string into an array of tokens
 * @str: string to be tokenized and packaged
 *
 * Return: vector array of string tokens
 */

char **tokenize(char *str)
{
	size_t index = 0, io = 0;
	int tkn = 1;
	char **tokens = NULL;
	char *buf = NULL, *token = NULL, *bufptr = NULL, *delim = " :\t\r\n";

	buf = duplicate_str(str);
	if (buf == NULL)
		return (NULL);
	bufptr = buf;

	while (*bufptr)
	{
		if (check_str(delim, *bufptr) != NULL && io == 0)
		{
			tkn++;
			io = 1;
		}
		else if (check_str(delim, *bufptr) == NULL && io == 1)
			io = 0;
		bufptr++;
	}
	tokens = malloc(sizeof(char *) * (tkn + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokens[index] = duplicate_str(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = NULL;

	free(buf);
	return (tokens);
}

/**
 * free_cmds - This program frees the cmd array
 * @m: pointer to an array of command line
 * arguments
 *
 * Return: void
 */
void free_cmds(char **m)
{
	int index = 0;

	if (m == NULL)
		return;
	while (m[index])
	{
		free(m[index]);
		index++;
	}
	free(m);
#include "shell.h"

/**
 * tokenizer - tokenizes input and stores it into an array
 *@input_string: input to be parsed
 *@delim: delimiter to be used, needs to be one character string
 *
 *Return: array of tokens
 */

char **tokenizer(char *input_string, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(input_string, delim, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}

/**
 *print - prints a string to stdout
 *@string: string to be printed
 *@stream: stream to print out to
 *
 *Return: void, return nothing
 */
void print(char *string, int stream)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(stream, &string[i], 1);
}

/**
 *remove_newline - removes new line from a string
 *@str: string to be used
 *
 *
 *Return: void
 */

void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 *_strcpy - copies a string to another buffer
 *@source: source to copy from
 *@dest: destination to copy to
 *
 * Return: void
 */

void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}

/**
 *_strlen - counts string length
 *@string: string to be counted
 *
 * Return: length of the string
 */

int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}}

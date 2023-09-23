#include "main.h"

/**
 * _exec - Execute with full command path.
 * @text: dynamically allocated array
 * @argv: list of command arguments
 * @cmd: command path.
 * Return: Always 0
*/
int _exec(char **text, char **argv, char *cmd)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
		/** Something went wrong. */
		perror(cmd);
		exit(-1);
	}
	else if (child_pid == 0)
	{
		/** Child execute first. */
		execve(cmd, text, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		/** Parent wait for child to execute. */
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		errno = status;
	}
	return (status);
}

/**
 * prepare_exec - Prepares execution.
 * @text: dynamically allocated array
 * @argv: list of command arguments
 * @cnt: count of iterations.
 * @ls: alias list
 * Return: Always 0
*/
void validator(char **text, char **argv, int cnt, alias_t **ls)
{
	char *cmd = NULL;
	int flag = 0;
	alias_t *temp = *ls;

	cmd = text[0];
	for (; temp != NULL; temp = temp->next)
		if (!_strcmp(temp->name, cmd))
			cmd = temp->val;

	if (access(cmd, X_OK) == 0 && _strcmp(cmd, "hbtn_ls") == 0 && text[1])
	{
		_exec(text, argv, cmd);
		return;
	}

	if (cmd[0] != '/' && cmd[0] != '.')
	{
		flag = 1;
		cmd = get_path_loc("PATH", cmd);
	}

	if (!cmd || (access(cmd, X_OK) == -1))
	{
		exec_error(argv[0], cnt, text[0]);
	}
	else
	{
		_exec(text, argv, cmd);
		if (flag)
			free(cmd);
	}
}

/**
 * prepare_subtext - Prepares subtext
 * @text: text
 * @lg: Line text
 * @cnt: count
 * @av: list argument
 * @ls: alias list
*/
void prepare(char **text, int attempt, char **av, alias_t **ls)
{
	int (*builtin)(char **text, int cnt, alias_t **ls);

	if (_strcmp(text[0], "exit") == 0)
		_exitshell(text, attempt, ls);

	builtin = builtins(text[0]);
	if (builtin)
		builtin(text, attempt, ls);
	else
		validator(text, av, attempt, ls);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:10:26 by tasano            #+#    #+#             */
/*   Updated: 2022/12/21 18:16:58 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <sys/types.h>

int	main(int argc, char *argv[])
{
	pid_t pid;
	t_commands_ast *ast;
	char *cmdline = "echo \"abc\" | grep \"a\" | cat nosuchfile 2> stderror.txt";

	//lexer => "echo" "abc" "|" "grep" "a" "|" "cat" "nosuchfile" "2>" "stderror.txt"
	//parser => "echo abc" "|" "grep" "a" "|" "cat" "nosuchfile" "2>" "stderror.txt"

	pid = fork();
			waitpid(-1, NULL, 0);
	if (pid == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			sleep(1);
			printf("this is child\n");
		}
		else
		{
			sleep(2);
			printf("this is parent2\n");
		}
	}
	else
		printf("this is parent1\n");

	return (0);
}

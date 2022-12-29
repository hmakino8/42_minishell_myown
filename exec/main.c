#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "err.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int		i = 0;
	int		cnt = 2;
	int		fd[2][2];
	pid_t	pid;
	char	*s = "from child";
	char	buf[10];

	while (i < cnt)
	{
		pipe(fd[i]);
		pid = fork();
		if (pid == 0)
			write(fd[i][1], s, strlen(s));
		else if (pid > 0)
		{
			read(fd[i][0], buf, 10);
			printf("%s\n",buf);
		}
		i++;
	}
}

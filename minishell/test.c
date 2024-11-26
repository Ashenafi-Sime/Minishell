/*#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	ft_fork(int *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

int main()
{
	int fd[2];
	pid_t pid;
	char buffer[13];

	ft_pipe(fd);
	ft_fork(&pid);

	if (pid == 0)
	{
		close(fd[0]);
		write(fd[1], "Hello parent!", 13);
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]);
		read(fd[0], buffer, 13);
		close(fd[0]);
		printf("Message from child: '%s'\n", buffer);
		exit(EXIT_SUCCESS);
	}
	return 0;
}*/

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main(void)
{
    char *rl;
	while (1){
	rl = readline("ourMiniShell > ");
    printf("%s\n", rl);
	free(rl);
	}
    
    return (0);
}

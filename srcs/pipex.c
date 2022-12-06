#include "pipex.h"

int		main(int argc, char	*argv[])
{
	int	fd[2];
	int	pfd[2];

	if (argc != 5)
		exit_message("Invalid number of arguments.");
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd[0] == -1)
		exit_message("Couldn't open infile.");
	if (pipe(pfd) < 0)
		exit_message("Error reading proccess fd.");
	fork_proccess(fd, pfd);
}

void	exit_message(char *msg)
{
	ft_printf("%s\n", msg);
	exit();
}

void	fork_proccess(int *files, int *pipes)
{
	int	id;

	id = fork();
	if (id < 0)
		exit_message("Fork error.");
	else if (id == 0)
	{
		//processo filho
	}
	else
	{
		//processo pai
		wait(NULL);
	}
}
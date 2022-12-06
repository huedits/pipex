#include "pipex.h"

int		main(int argc, char	*argv[])
{
	int	fd[2];

	if (argc != 4)
		exit_message("Invalid number of arguments.");
	fd[0] = open(argv[0], O_RDONLY);
	fd[1] = open(argv[3], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd[0] == -1)
		exit_message("Couldn't open infile.");
	
}

void	exit_message(char *msg)
{
	ft_printf("%s\n", msg);
	exit();
}
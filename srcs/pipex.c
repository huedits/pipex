#include "pipex.h"

int		main(int argc, char	*argv[], char *envp[])
{
	int	infd;
	int	outfd;

	if (argc != 5)
		exit_message("Invalid number of arguments.");
	infd = open_file(argv[1], INFILE);
	outfd = open_file(argv[4], OUTFILE);
	dup2(infd, STDIN);
	dup2(outfd, STDOUT);
}

int		open_file(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
			exit_message("Coudl't read infile.");
		return(open(filename, O_RDONLY));
	}
	else
		return(open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664))
}

void	exit_message(char *msg)
{
	ft_printf("%s\n", msg);
	exit();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:32:00 by vimatheu          #+#    #+#             */
/*   Updated: 2022/12/13 18:32:00 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char	*argv[], char *envp[])
{
	int	infd;
	int	outfd;
	int	fid;

	if (argc == 5)
	{
		infd = open_file(argv[1], INFILE);
		outfd = open_file(argv[4], OUTFILE);
		dup2(infd, STDIN);
		dup2(outfd, STDOUT);
		fork_proccess(argv[2], envp, infd);
		fid = fork();
		if (fid == 0)
			exec(argv[3], envp);
		else
			waitpid(fid, NULL, 0);
	}
	else
	{
		write(STDERR, "Invalid number of arguments.\n", 29);
		return (1);
	}
	return (0);
}

int	open_file(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, "pipex: ", 7);
			write(STDERR, filename, ft_strchrsize(filename, 0));
			write(STDERR, ": No such file or directory\n", 28);
			return (STDIN);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664));
}

void	fork_proccess(char *cmd, char *env[], int infd)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		if (infd == STDIN)
			exit(1);
		else
			exec(cmd, env);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
}

char	*get_path(char *cmd, char *env[])
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && ft_strchrsize(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_strchrsize(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strchrsize(path, ':') + 1;
	}
	return (cmd);
}

void	exec(char *cmd, char *env[])
{
	char	**args;
	char	*path;
	int		i;

	args = ft_split(cmd, ' ');
	if (ft_strchrsize(args[0], '/') > -1)
		path = args[0];
	else
		path = get_path(args[0], env);
	execve(path, args, env);
	write(STDERR, "pipex: ", 7);
	write(STDERR, cmd, ft_strchrsize(cmd, 0));
	write(STDERR, ": command not found\n", 20);
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	exit(127);
}

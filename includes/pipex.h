#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "ft_printf.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

void    exit_message(char *msg);
int		open_file(char *filename, int mode);
void	fork_proccess(char *cmd, chr *env[], int infd);
char	*get_path(char *cmd, char *env[]);
char	*ft_strndup (char *str, unsigned int n);
char	*path_join (char *path, char *bin);

#endif
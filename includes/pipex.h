#include <fcntl.h>
#include <unistd.h>
#include <system.h>
#include "ft_printf.h"

void    exit_message(char *msg);
void	fork_proccess(int *files, int *pipes);
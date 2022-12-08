#include "pipex.h"

void	exit_message(char *msg)
{
	ft_printf("%s\n", msg);
	exit();
}

char	*path_join (char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (str_ichr(path, 0) + str_ichr(bin, 0) + 2));
	i = 0;
	j = 0;
	while (path[j])
		joined[i++] = path[j++];
	joined[i++] = '/';
	j = 0;
	while (bin[j])
		joined[i++] = bin[j++];
	joined[i] = 0;
	return (joined);
}

char	*ft_strndup (char *str, unsigned int n)
{
	char				*duped;
	unsigned int		i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}

int		ft_strchrsize(char *str, char ch)
{
	int	count;

	count = 0;
	while (*str && *str != ch)
		count++;
	if (*str == ch)
		return (count);
	return (-1);
}
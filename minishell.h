#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_data
{
	char **str;
	char *data;
	char *name;
}		t_data;

char	**ft_split(char const *s, char c);
void    which_echo_command(char *array, int flag);
void which_command(char **str, t_data *not_parsed);
int	ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_memset(void *str, int letter, size_t n);
#endif

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
	char *lol;
}		t_data;

char **split(char *str, char c);
void    which_echo_command(char *array, int flag);
int	ft_strcmp(const char *s1, const char *s2);
#endif
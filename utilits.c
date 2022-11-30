#include "minishell.h"

int word_count(char *str, char c)
{
	int i = 0;
	int len = 1;
	while(str[i] != '\0')
	{
		if(str[i] == c)
			len++;
		i++;
	}
	return (len);
}
char **split(char *str, char c)
{
	char **res;
	int k = 0;
	int i = 0;
	int j = 0;
	res = (char **)malloc(sizeof(char *) * word_count(str, c) + 1);
	while(str[i] == c)
		i++;
	while(k < word_count(str,c) && str[i])
	{
		while(str[i] == c)
			i++;
		j = i;
		while(str[i++] != c && str[i]);
		res[k] = (char *)malloc(sizeof(char) * i + 1);
		i = j;
		j = 0;
		while(str[i] != c && str[i])
		{
				res[k][j++] = str[i++];
		}
		res[k][j] = 0;
		k++;
		i++;
	}
	return (res);
}

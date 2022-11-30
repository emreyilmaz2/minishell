#include "minishell.h"
#include "string.h"
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			cnt;
	unsigned int	diff;

	cnt = 0;
	diff = 0;
	while (!diff && (s1[cnt] != 0) && (s2[cnt] != 0))
	{
		diff = (unsigned char)s1[cnt] - (unsigned char)s2[cnt];
		cnt++;
	}
	if (!diff && (s1[cnt] == 0 || s2[cnt] == 0))
		diff = (unsigned char)s1[cnt] - (unsigned char)s2[cnt];
	return (diff);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	y;

		i = 0;
		y = 0;
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (i < ft_strlen(s1))
	{
		s3[i] = s1[i];
		i++;
	}
	while (y < ft_strlen(s2))
	{
		s3[i] = s2[y];
		i++;
		y++;
	}
	s3[i] = '\0';
	return (s3);
}
char *ft_name(char *name)
{
	name = malloc(sizeof(char) * 17 + 1); 
	name = strcat(name, "\033[0;32m@minishell-> \033[0m");
	// name = ft_strjoin(getenv("USER"),"\033[0;32m @minishell->\033[0m");
	return (name);
}

void which_command(char **str, t_data *not_parsed)
{
	if(!ft_strcmp(*str, "pwd"))
			printf("%s\n", getenv("PWD"));
	else if(!ft_strcmp(*str,"echo"))
	{
		if(!ft_strcmp(*(++str),"-n"))
			which_echo_command(not_parsed->lol, 0);
		else
			which_echo_command(not_parsed->lol, 1);
	}
	else if(!ft_strcmp(*str,"env"))
	{
		exit(1);
	}
	else if(!ft_strcmp(*str,"exit"))
	{
		exit(1);
	}
	else if(!ft_strcmp(*str,"cd"))
	{

	}
	else if(!ft_strcmp(*str,"ls"))
	{
		printf("%s\n", getenv("LS"));
	}
	else
		write(1, "~not a command~\n", 16);
}

int main(void)
{ 
	// t_list *list;
	// list = malloc(sizeof(t_list));
	t_data *can;
	char *name = NULL;
	can = malloc(sizeof(t_data));
	name = ft_name(name);
	while(1)
	{
		can->lol = readline(name);
		char **str = split(can->lol, ' ');
		which_command(str, can);
		free(str);
		// int x = 0;
		// char *str = malloc(sizeof(char *));
		// printf("->");
		// scanf("%d", &x);
		// if(x == 1)
		// 	return(0);
		// else
		// {
		// 	scanf(" %[^\n]",str);
		// 	char **toto = split(str, ' ');
		// 	for(int i=0; toto[i]; i++)
		// 		printf("%s\n", toto[i]);
		// }


			// printf("%sA\n", split(argv[1], '-')[1]);
	}
	// while(list->next != NULL && list->branch != NULL)
	// {
		
	// }
	// char *str;
	// int len = 0;
	// int i = 1;
	// int j = 0;
	// while(i < argc && argv[i])
	// {
	// 	j = 0;
	// 	while(argv[i][j++])
	// 		len++;
	// 	i++;
	// }
	// str = (char *)malloc(sizeof(char) * len + 1);
	//heredoc var mı yok mu bakmadım buraya bak
}
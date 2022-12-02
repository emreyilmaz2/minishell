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
void	ft_name(t_data *can, char **env)
{
	can->name = ft_strjoin(getenv("USER"),"\033[0;32m@minishell->\033[0m");
}

void get_readline(t_data *can)
{
	if(can->data)
	{
		free(can->data);
		
	}
	can->data = readline(can->name);
	if(can->data)
		add_history(can->data);
}

void	ft_loop(t_data *can)
{
	int k;
	while(1)
	{

		get_readline(can);
		can->str = ft_split(can->data, ' ');
		which_command(can->str, can);
		k = 0;
		while(can->str[k])
			free(can->str[k++]);
		free(can->str);
	}
}

void which_command(char **str, t_data *not_parsed)
{
	if(!ft_strcmp(*str, "pwd"))
			printf("%s\n", getenv("PWD"));
	else if(!ft_strcmp(*str,"echo"))
	{
		if(!ft_strcmp(*(++str),"-n"))
			which_echo_command(not_parsed->data, 0);
		else
			which_echo_command(not_parsed->data, 1);
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

int main(int argc, char **argv, char **env)
{
	t_data *can;
	can = malloc(sizeof(t_data));
	can->name = NULL;
	ft_name(can,env);
	ft_loop(can);

}

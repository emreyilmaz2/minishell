#include "minishell.h"

t_env	*g_list;
// void print(char *s)
// {
// 	printf("   |-------%*s%*s-------|\n",10+(int)strlen(s)/2,s,10-(int)strlen(s)/2,"");
// }

// void	print_nodes(t_main_list	*node_list)
// {
// 	int i = 0;
// 	int m = 0;
// 	while (node_list)
// 	{
// 		printf("bu buraya %d. gelisim\n",m+1);
//         printf("   ____________________________________\n");
//         printf("   |--------------NODE %d pipe_cmd--------------|\n", (m++)+1);
//         printf("   |----------------------------------|\n");
// 		print(node_list->pipe_cmd);
//         printf("   |__________________________________|\n");
// 		printf("bu buraya %d. gelisim\n",m+1);
//         printf("   ____________________________________\n");
//         printf("   |--------------NODE %d infile_name--------------|\n", (m++)+1);
//         printf("   |----------------------------------|\n");
// 		// if(node_list->infile_name)
// 		// {
// 		// 		i = -1;
// 		// 	while(node_list->infile_name[++i])
// 		// 		print(node_list->infile_name[i]);
// 		// }
// 		// else 
// 		//	printf("-\n");
//         printf("   |__________________________________|\n");
// 				printf("bu buraya %d. gelisim\n",m+1);
//         printf("   ____________________________________\n");
//         printf("   |--------------NODE %d outfile_name_l--------------|\n", (m++)+1);
//         printf("   |----------------------------------|\n");
// 			if(node_list->outfile_name_l)
// 		{
// 			i = -1;
// 			while(node_list->outfile_name_l[++i])
// 				print(node_list->outfile_name_l[i]);
// 		}
// 		else
// 			printf("-\n");
// 	    printf("   |__________________________________|\n");
// 				printf("bu buraya %d. gelisim\n",m+1);
//         printf("   ____________________________________\n");
//         printf("   |--------------NODE %d outfile_name_r--------------|\n", (m++)+1);
//         printf("   |----------------------------------|\n");
// 			if(node_list->outfile_name_r)
// 		{
// 			i = -1;
// 			while(node_list->outfile_name_r[++i])
// 				print(node_list->outfile_name_r[i]);
// 		}
// 		else 
// 			printf("-\n");
// 		printf("   |__________________________________|\n");
// 				printf("bu buraya %d. gelisim\n",m+1);
//         printf("   ____________________________________\n");
//         printf("   |--------------NODE %d eof --------------|\n", (m++)+1);
//         printf("   |----------------------------------|\n");
// 		if(node_list->eof)
// 			print(node_list->eof);
//         printf("   |__________________________________|\n");
// 				printf("bu buraya %d. gelisim\n",m+1);
//         printf("   ____________________________________\n");
//         printf("   |--------------NODE %d append_r--------------|\n", (m++)+1);
//         printf("   |----------------------------------|\n");
// 		if(node_list->append_r)
// 		{
// 			i = -1;
// 			while(node_list->append_r[++i])
// 				print(node_list->append_r[i]);
// 		}
// 		else
// 			printf("-\n");
// 		printf("   |__________________________________|\n");
// 				printf("bu buraya %d. gelisim\n",m+1);
//         printf("   ____________________________________\n");
//         printf("   |--------------NODE %d append_l--------------|\n", (m++)+1);
//         printf("   |----------------------------------|\n");
// 		if(node_list->append_l)
// 		{
// 			i = -1;
// 			while(node_list->append_l[++i])
// 				print(node_list->append_l[i]);
// 		}
// 		else 
// 			printf("-\n");
// 		printf("   |__________________________________|\n");
// 				printf("bu buraya %d. gelisim\n",m+1);
//         printf("   ____________________________________\n");
//         printf("   |--------------NODE %d cmd--------------|\n", (m++)+1);
//         printf("   |----------------------------------|\n");
// 		if(node_list->cmd)
// 			print(node_list->cmd);
//         else
// 			printf("-\n");
// 		printf("   |__________________________________|\n");
// 		    printf("   ____________________________________\n");
//         printf("   |--------------NODE %d flag--------------|\n", (m++)+1);
//         printf("   |----------------------------------|\n");
// 			if(node_list->flag)
// 			print(node_list->flag);
//         else
// 			printf("-\n");
//         printf("   |__________________________________|\n");
// 		printf("   ____________________________________\n");
//         printf("   |--------------NODE %d args--------------|\n", (m++)+1);
//         printf("   |----------------------------------|\n");
// 		i = -1;
// 		// while(node_list->args[++i])
// 		// 	printf("%s\n",node_list->args[i]);
//         printf("   |__________________________________|\n");
// 		node_list = node_list->next;
// 	}
// }
void	convert_space2(t_main_list **m_list)
{
	int (j) = 0;
	int (i) = -1;
	int (flag) = 0;
	while ((*m_list)->two_d_cmd[++i])
	{
		j = -1;
		while((*m_list)->two_d_cmd[i][++j])
		{
			if ((*m_list)->two_d_cmd[i][j] == '`')
				(*m_list)->two_d_cmd[i][j] = ' ';
		}
	}
}
void multi_close(t_main_list *m_list)
{
	int j;
	int out = 0;
	int app = 0;
	while(m_list)
	{
		out = token_count(m_list,">");
		app = token_count(m_list,">>");
		while(m_list->append_fd_r[--app])
			close(m_list->append_fd_r[app]);
		app = token_count(m_list,">>") - 1;
		while(m_list->outfile_fd_r[--app])
			close(m_list->outfile_fd_r[app]);
		out = token_count(m_list,">");
		while(m_list->append_fd_l[--out])
			close(m_list->append_fd_l[out]);
		out = token_count(m_list,">");
		while(m_list->outfile_fd_r[--out])
			close(m_list->outfile_fd_r[out]);
		m_list = m_list->next;
	}
}
void print_list(t_mini *sadi)
{
	if (!sadi)
		return;
	while (sadi->prev)
		sadi=sadi->prev;
	while (sadi != NULL)
	{
		printf("%s\n", sadi->data);
		sadi = sadi->next;
	}
}


int limited_cmp(char *s1, char *s2)
{
	int i;
	i = 0;
	while(s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if(!s1[i] && !s2[i])
		return(0);
	else if(s1[i] && !s2[i])
		return(0);
	else
		return (1);
}

void	get_readline(t_data *can)
{
	can->data = readline(g_list->name);
	if(!can->data)
		exit(1);
	if (ft_strcmp(can->data, ""))
		add_history(can->data);
}

t_mini *build_list(char **string, t_mini *list)
{
	int i = 0;
	int j = -1;
	t_mini *list_two;
	t_mini *tmp;
	list->data = NULL;
	list_two = list;
	tmp = NULL;
	list->data = malloc(ft_strlen(string[i])+1);
	while (string[i][++j])
		list->data[j] = string[i][j];
	list->data[j] = '\0';
	list->next = NULL;
	list->prev = NULL;
	while (string[++i] != NULL)
	{
		list->next = malloc(sizeof(t_mini));
		tmp = list;
		list = list->next;
		list->prev = tmp;
		list->data = malloc(ft_strlen(string[i]) + 1);
		j = -1;
		while (string[i][++j])
			list->data[j] = string[i][j];
		list->data[j] = '\0';
		list->next = NULL;
	}
	return (list_two);
}

void	signal_replace_line(int num)
{
	(void)num;
	printf("\n");
	printf("%s", g_list->name);
	fflush(stdout);
	// rl_replace_line("", 0);
	// rl_on_new_line();
	// rl_redisplay();
}

void signal_quit(int signum)
{
	write(1, "exit", 4);
	exit(0);
}

int	twod_token_len(char **str, char c)
{
	int (i) = 0;
	int (count) = 0;
	while (str[i])
	{
		if (!ft_strcmp(str[i], &c))
			count++;
		i++;
	}
	return (count);
}

int token_countlst(t_mini *list, char *delimeter)
{
	int (i) = 0;
	int (len) = 0;
	while (list)
	{
		if (!ft_strcmp(list->data, delimeter))
			len++;
		i++;
	}
	return (len);
}

int token_countstr(char *str,char delimeter)
{
	int (i) = 0;
	int (len) = 0;
	while(str[i])
	{
		if(str[i] == delimeter)
			len++;
		i++;
	}
	return(len);
}

int	token_count(t_main_list *m_list, char *delimeter)
{
	int (i) = 0;
	int (len) = 0;
	while (m_list->two_d_cmd[i])
	{
		if (!ft_strcmp(m_list->two_d_cmd[i], delimeter))
			len++;
		i++;
	}
	return (len);
}
	
int ft_compare_c(char *str, t_main_list *m_list)
{
	int i = -1;
	while(m_list->outfile_name_l[++i])
	{
		if(!fix_cmp(m_list->outfile_name_l[i],str))
			return(0);
	}
	i = -1;
	while(m_list->outfile_name_r[++i])
	{
		if(!fix_cmp(m_list->outfile_name_r[i],str))
			return(0);
	}
	i = -1;
	while(m_list->append_r[++i])
	{
		if(!fix_cmp(m_list->append_r[i],str))
			return(0);
	}
	i = -1;
	while(m_list->append_l[++i])
	{
		if(!fix_cmp(m_list->append_l[i],str))
			return(0);
	}
	i = -1;
	while(m_list->infile_name_l[++i])
	{
		if(!fix_cmp(m_list->infile_name_l[i],str))
			return(0);
	}
	i = -1;
	while(m_list->infile_name_r[++i])
	{
		if(!fix_cmp(m_list->infile_name_r[i],str))
			return(0);
	}
	if(!fix_cmp(m_list->cmd,str))
		return	(0);
	if(!fix_cmp(m_list->eof,str))
		return	(0);
	if(!fix_cmp(m_list->flag,str))
		return	(0);
	return (1);
}


void execute(int tmp_fd, t_main_list *m_list)
{
	dup2(tmp_fd, 0);
	close(tmp_fd);
	execve(m_list->path, m_list->args, g_list->environment);//NULLU ENV YAP
}

void ft_echo(t_main_list *m_list)
{
	char **arr = ft_calloc(sizeof(char *), twod_len(m_list->args));
	int (i) = 0;
	int (flag) = 0;
	int (j) = 0;
	while(m_list->args[i])
	{
		if(!fix_cmp(m_list->args[i], m_list->cmd))
			i++;
		arr[j++] = ft_strdup(m_list->args[i]);
		i++;
	}
	i = -1;
	while(++i<j)
	{
		if(!ft_strcmp(arr[i], "-n"))
			flag = 1;
		else if(i+1 != j)
			printf("%s ",arr[i]);
		else
			printf("%s",arr[i]);
	}
	if(flag == 0)
		printf("\n");
	two_d_free(arr);
}

void ft_pwd(t_main_list *m_list, t_expander *exp)
{
	int (j) = -1;
	char *arr;
	while(exp->env_head[++j])
	{
		if(!ft_strcmp(exp->env_head[j],"PWD"))
		{
			arr = ft_strdup(exp->env_tail[j]);
			break;
		}
	}
	printf("%s\n",arr);
	free(arr);
}

void ft_cd(t_main_list *m_list, t_expander **exp)
{
	char *arr;
	char *tmp;
	char *lol;
	int (i) = 0;
	int (j) = -1;
	if(!ft_strcmp(m_list->args[0],"cd") && m_list->args[1])
	{
		while((*exp)->env_head[++j])
		{
			if(!ft_strcmp((*exp)->env_head[j],"PWD"))
			{
				arr = ft_strdup((*exp)->env_tail[j]);
				break;
			}
		}
		while(m_list->args[i])
		{
			if(!fix_cmp(m_list->args[i], m_list->cmd))
			{	
				i++;
				tmp = ft_strdup(m_list->args[i]);
			}
			i++;
		}
		// i = -1;
		// while(g_list->environment[i])
		// {
		// 	if(ft_str_in_str(g_list->environment[i],0,"OLDPWD"))
		// }
		// //g_list->enviroment
		if(chdir(tmp))
		{
			printf("arr: \n");
			free((*exp)->env_tail[j]);
			(*exp)->env_tail[j] = ft_strdup(arr);
			// update_env(exp,j);
		}
		free(arr);
		free(tmp);
	}
	else
		chdir("~");
}

void ft_env()
{
	int (j) = -1;
	while(g_list->environment[++j] && j < g_list->sayac)
		printf("%s\n",g_list->environment[j]);
}

void ft_exit(t_main_list *m_list)
{
	if(!ft_strcmp(m_list->args[0],"exit") && !m_list->args[2])
		exit(0);
}

void which_buildin(t_main_list *m_list, t_expander *exp)
{
    if(!ft_strcmp(m_list->args[0], "echo"))
        ft_echo(m_list);
    // else if(!ft_strcmp(m_list->args[0], "cd"))
    //     ft_cd(m_list, &exp);
    else if(!ft_strcmp(m_list->args[0], "pwd"))
        ft_pwd(m_list,exp);
    else if(!ft_strcmp(m_list->args[0], "export"))
        ft_export(m_list);
    else if(!ft_strcmp(m_list->args[0], "unset"))
        ft_unset(m_list);
    else if(!ft_strcmp(m_list->args[0], "env"))
        ft_env();
    else if(!ft_strcmp(m_list->args[0], "exit"))
        ft_exit(m_list);
    else
        return ;
}

int is_builtin(t_main_list *m_list)
{
    return(!ft_strcmp(m_list->args[0], "env")
        | !ft_strcmp(m_list->args[0], "exit")
        | !ft_strcmp(m_list->args[0], "unset")
        | !ft_strcmp(m_list->args[0], "export")
        | !ft_strcmp(m_list->args[0], "pwd")
        | !ft_strcmp(m_list->args[0], "cd")
        | !ft_strcmp(m_list->args[0], "echo"));
}

void executer(t_main_list *m_list, t_mini *list, t_expander *exp)
{
	int fd[2];
	int tmp_fd;
	tmp_fd = dup(0);
	while(m_list)
	{
		if(is_builtin(m_list))
			which_buildin(m_list, exp);
		else if(m_list->next)
		{
			pipe(fd);
			if(fork() == 0)
			{
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				execute(tmp_fd, m_list);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
		else
		{
			if(fork() == 0)
			{
				execute(tmp_fd,m_list);
				exit(0);
			}
			else
			{
				close(tmp_fd);
				while(waitpid(-1, NULL, WUNTRACED) != -1);
				tmp_fd = dup(0);
			}
		}
		m_list = m_list->next;
	} 
}

void ft_loop()
{
	t_main_list	*m_l;
	t_mini	*list;
	t_data	*can;
	t_expander	*exp;
	while (1)
	{
		can = malloc(sizeof(t_data));
		signal(SIGINT, &signal_replace_line);
		signal(SIGQUIT, SIG_IGN);
		get_readline(can);
		if (ft_strcmp(can->data, "") && checker(can->data))
		{
			list = lexer(can);
			exp = expander(list);
			m_l = parser(list);
			executer(m_l,list,exp);
			multi_close(m_l);
			multi_free(m_l, list, exp, can);
		}
		free(can->data);
		free(can);
	}
}

int main(int argc, char **argv, char **env)
{
    int i = -1;
    g_list = malloc(sizeof(t_env));
    g_list->environment = env;
    g_list->sayac = twod_len(g_list->environment);
	g_list->name = ft_strdup("\033[0;34m@minishell-> \033[0m");
    g_list->export = malloc(sizeof(char *) * 100);
    while (g_list->environment[++i])
		g_list->export[i] = ft_strdup(env[i]);
    ft_loop();
    two_d_free(g_list->export);
    two_d_free(g_list->environment);
	free(g_list->name);
    free(g_list);
    return (0);
}

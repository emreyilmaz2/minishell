/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:04:12 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/25 15:43:06 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// void multi_close(t_main_list *m_list, int a)
// {
// 	int j = 0;
// 	int out = 0;
// 	int app = 0;
// 	while(m_list)
// 	{
// 		out = token_count(m_list,">");
// 		app = token_count(m_list,">>");
// 		if(m_list->append_fd_r[app - 1])
// 			close(m_list->append_fd_r[app - 1]);
// 		if(m_list->outfile_fd_r[out - 1])
// 			close(m_list->outfile_fd_r[out - 1]);
// 		m_list = m_list->next;
// 	}
// }
void sort_args(t_main_list **m_list)
{
	char **arr;
	char *temp;
	int (i) = -1;
	int (j) = 0;
	arr = ft_calloc(sizeof(char *),twod_len((*m_list)->args) + 1);
	while((*m_list)->args[++i])
	{
		if(!fix_cmp((*m_list)->args[i],(*m_list)->cmd))
		{
			arr[j++] = ft_strdup((*m_list)->args[i]);
			arr[j++] = ft_strdup((*m_list)->flag);
		}
		else if(!fix_cmp((*m_list)->args[i],(*m_list)->flag))
			usleep(1);
		else
			arr[j++] = ft_strdup((*m_list)->args[i]);
	}
	i = -1;
	while(arr[++i])
		(*m_list)->args[i] = ft_strdup(arr[i]);
	two_d_free(arr);
}

t_main_list	*parser(t_mini *list)
{
	t_main_list	*m_list;
	t_main_list	*temp;
	int (i) = 0;

	m_list = build_main_list(m_list, list);
	temp = m_list;
	pipe_cmd(temp, list);;
	while (temp)
	{
		temp->two_d_cmd = ft_split(temp->pipe_cmd,' ');
		convert_space2(&temp);
		is_there_flag(temp);
		find_cmd(temp);
		infile_fd(temp, -1, 0, 0);
		outfile_fd(temp, 0, -1, 0);
		// int fd = open("/dev/tty", O_WRONLY);
		// dup2(fd, fileno(stdout));
		eof_fd(temp);
		append_fd(temp);
		all_args(temp);
		i = -1;
		if(m_list->flag)
			sort_args(&temp);
		if(temp->next)
			temp = temp->next;
		else
			break;		
	}
	return (m_list);
}

void	ft_initialize(t_main_list *temp)
{
	temp->path = NULL;
	temp->args = NULL;
	temp->eof = NULL;
	temp->pipe_cmd = NULL;
	temp->append_r = NULL;
	temp->append_l = NULL;
	temp->append_fd_l = NULL;
	temp->append_fd_r = NULL;
	temp->two_d_cmd = NULL;
	temp->outfile_name_r = NULL;
	temp->outfile_name_l = NULL;
	temp->outfile_fd_r = 0;
	temp->outfile_fd_l = 0;
	temp->infile_name_l = NULL;
	temp->infile_name_r = NULL;
	temp->flag = NULL;
	temp->cmd = NULL;
	temp->infile_fd_r = 0;
	temp->infile_fd_l = 0;	
}

t_main_list	*build_main_list(t_main_list *m_list,t_mini *list)
{
	t_main_list	*tmp;
	int (i) = 0;
	int (count) = 0;

	m_list = malloc(sizeof(t_main_list));
	tmp = m_list;
	ft_initialize(tmp);
	while (list)
	{
		if (!ft_strcmp(list->data, "|"))
			count++;
		list = list->next;
	}
	i = -1;
	while (++i < count)
	{
		tmp->next = malloc(sizeof(t_main_list));
		if(i != count)
			tmp = tmp->next;
		ft_initialize(tmp);
	}
	tmp->next = NULL;
	return (m_list);
}

void	pipe_cmd(t_main_list *m_list, t_mini *list)
{
	t_main_list *tmp;
	char *arr;
	tmp = m_list;
	while (list)
	{
		while (fix_cmp(list->data,"|") && list->data)
		{
			if (list->data && !tmp->pipe_cmd)
				tmp->pipe_cmd = ft_strdup(list->data);
			else
			{
				arr = ft_strjoin(tmp->pipe_cmd, " ");
				free(tmp->pipe_cmd);
				tmp->pipe_cmd = ft_strjoin(arr, list->data);
				free(arr);
			}
			if (list->next)
				list = list->next;
			else
				break;	
		}
		if (list->next)
			tmp = tmp->next;
		if (list->next)
			list = list->next;
		else 
			break;
	}
}

void	is_there_flag(t_main_list *m_list)
{
	int	i;

	i = 0;
	while (m_list->two_d_cmd[i])
	{
		if (m_list->two_d_cmd[i][0] == '-')
				m_list->flag = ft_strdup(m_list->two_d_cmd[i]);
		else 
			m_list->flag = NULL;
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:04:12 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 06:25:51 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_args(t_main_list **m_list)
{
	char **(arr) = ft_calloc(sizeof(char *),
			ft_size_array((*m_list)->args) + 1);
	int (i) = -1;
	int (j) = 0;
	while (ft_strcmp((*m_list)->cmd, "path") && (*m_list)->args[++i])
	{
		if (!fix_cmp((*m_list)->args[i], (*m_list)->cmd))
		{
			arr[j++] = ft_strdup((*m_list)->args[i]);
			arr[j++] = ft_strdup((*m_list)->flag);
			free((*m_list)->args[i]);
		}
		else if (!fix_cmp((*m_list)->args[i], (*m_list)->flag))
			free((*m_list)->args[i]);
		else
		{
			arr[j++] = ft_strdup((*m_list)->args[i]);
			free((*m_list)->args[i]);
		}
	}
	i = -1;
	while (arr[++i])
		(*m_list)->args[i] = ft_strdup(arr[i]);
	two_d_free(arr);
}

void	flag_cmd(t_main_list *temp)
{
	if (fix_cmp(temp->tdm[0], temp->cmd)
		&& !is_builtin3(temp) && !fix_cmp(temp->cmd, "path"))
		g_list->f = 0;
	if (temp->path && fix_cmp(temp->cmd, "path"))
		g_list->f = 1;
	if (g_list->f == 0)
	{
		printf("minishell: command not found: %s\n", temp->tdm[0]);
		g_list->exit_status = 127;
	}
}

t_main_list	*parser(t_mini *list, t_main_list *m_list)
{
	m_list = build_main_list(m_list, list);
	t_main_list *(temp) = m_list;
	pipe_cmd(temp, list);
	while (temp)
	{
		temp->tdm = ft_split(temp->pipe_cmd, ' ');
		convert_space2(&temp);
		find_cmd(temp);
		flag_cmd(temp);
		if (g_list->f)
		{
			eof_fd(temp);
			outfile_fd(temp, token_count(m_list, ">"), -1, 0);
			append_fd(temp, token_count(m_list, ">>"), -1, 0);
			all_args(temp);
			if (temp->flag)
				sort_args(&temp);
		}
		if (temp->next)
			temp = temp->next;
		else
			break ;
	}
	return (m_list);
}

t_main_list	*build_main_list(t_main_list *m_list, t_mini *list)
{
	t_main_list	*tmp;

	int (i) = 0;
	int (count) = 0;
	m_list = ft_calloc(sizeof(t_main_list), 1);
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
		tmp->next = ft_calloc(sizeof(t_main_list), 1);
		if (i != count)
			tmp = tmp->next;
		ft_initialize(tmp);
	}
	tmp->next = NULL;
	return (m_list);
}

void	pipe_cmd(t_main_list *m_list, t_mini *list)
{
	t_main_list *(tmp) = m_list;
	while (list)
	{
		while (fix_cmp(list->data, "|") && list->data)
		{
			if (list->data && !tmp->pipe_cmd)
				tmp->pipe_cmd = ft_strdup(list->data);
			else
				ft_parse_pipe_cmd(&tmp, list);
			if (list->next)
				list = list->next;
			else
				break ;
		}
		if (list->next)
		{
			tmp = tmp->next;
			list = list->next;
		}
		else
			break ;
	}
}

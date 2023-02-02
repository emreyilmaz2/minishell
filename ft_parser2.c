/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:30:58 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 05:32:20 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(void)
{
	perror("No file or directory");
	signal_replace_line(SIGINT);
}

void	all_args2(t_main_list **m_list, int *i, int *l)
{
	if (!fix_cmp((*m_list)->eof, (*m_list)->tdm[*i]))
	{
		(*m_list)->args[(*l)++] = ft_strdup(".heredoc");
		(*i)++;
	}
	else if (!fix_cmp((*m_list)->eof, (*m_list)->tdm[(*i)]))
		(*i)++;
	else
	{
		if (ft_compare_parser((*m_list)->tdm[(*i)], (*m_list)))
		(*m_list)->args[(*l)++] = ft_strdup((*m_list)->tdm[(*i)++]);
		else
			(*i)++;
	}
}

void	all_args(t_main_list *m_list)
{
	char *(arr);
	int (i) = 0;
	int (l) = 0;
	m_list->args = calloc(sizeof(char *), 1000);
	while (m_list->tdm[i])
	{
		arr = ft_after_last_slash(m_list->tdm[i]);
		if (!fix_cmp(m_list->flag, m_list->tdm[i]))
			m_list->args[l++] = ft_strdup(m_list->tdm[i++]);
		else if (!fix_cmp(m_list->cmd, m_list->tdm[i])
			|| (!fix_cmp(arr, m_list->cmd)))
		{
			m_list->args[l++] = ft_strdup(m_list->cmd);
			i++;
		}
		else if (!fix_cmp(m_list->append_l[0], m_list->tdm[i]))
				m_list->args[l++] = ft_strdup(m_list->tdm[i++]);
		else if (!fix_cmp(m_list->outfile_l[0], m_list->tdm[i]))
				m_list->args[l++] = ft_strdup(m_list->tdm[i++]);
		else if (operator_cmp(m_list, i))
			i++;
		else
			all_args2(&m_list, &i, &l);
		free(arr);
	}
}

void	is_there_flag(t_main_list *m_list)
{
	int (i) = 0;
	int (flag) = 0;
	while (m_list->tdm[i])
	{
		if (m_list->tdm[i][0] == '-')
		{
			m_list->flag = ft_strdup(m_list->tdm[i]);
			flag++;
		}
		i++;
	}
	if (!flag)
		m_list->flag = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 04:02:17 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 05:32:54 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_compare_parser(char *str, t_main_list *m_list)
{
	int (i) = -1;
	while (m_list->outfile_l[++i])
	{
		if (!fix_cmp(m_list->outfile_l[i], str))
			return (0);
	}
	i = -1;
	while (m_list->outfile_r[++i])
	{
		if (!fix_cmp(m_list->outfile_r[i], str))
			return (0);
	}
	i = -1;
	while (m_list->append_r[++i])
	{
		if (!fix_cmp(m_list->append_r[i], str))
			return (0);
	}
	if (ft_compare_parser2(str, m_list))
		return (1);
	return (0);
}

int	ft_compare_parser2(char *str, t_main_list *m_list)
{
	int (i) = -1;
	while (m_list->append_l[++i])
	{
		if (!fix_cmp(m_list->append_l[i], str))
			return (0);
	}
	if (!fix_cmp(m_list->cmd, str))
		return (0);
	if (!fix_cmp(m_list->eof, str))
		return (0);
	if (!fix_cmp(m_list->flag, str))
		return (0);
	return (1);
}

void	compare_all(t_main_list **m_list, int *i, int *l)
{
	if (ft_compare_parser((*m_list)->tdm[(*i)], (*m_list)))
		(*m_list)->args[(*l)++] = ft_strdup((*m_list)->tdm[(*i)++]);
	else
		(*i)++;
}

int	operator_cmp(t_main_list *m_list, int i)
{
	if (!fix_cmp(m_list->tdm[i], "<"))
		return (1);
	else if (!fix_cmp(m_list->tdm[i], ">"))
		return (1);
	else if (!fix_cmp(m_list->tdm[i], ">>"))
		return (1);
	else if (!fix_cmp(m_list->tdm[i], "<<"))
		return (1);
	else if (!fix_cmp(m_list->tdm[i], "|"))
		return (1);
	return (0);
}

void	ft_parse_pipe_cmd(t_main_list **tmp, t_mini *list)
{
	char *(arr);
	arr = ft_strjoin((*tmp)->pipe_cmd, " ");
	free((*tmp)->pipe_cmd);
	(*tmp)->pipe_cmd = ft_strjoin(arr, list->data);
	free(arr);
}

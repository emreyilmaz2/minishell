/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:27:17 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 05:59:46 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	outfile_dup2(t_main_list *m_list, int j, int l)
{
	if (m_list->outfile_l[j])
		m_list->outfile_fd_l[j] = open(m_list->outfile_l[j],
				O_WRONLY | O_CREAT, 0774);
	m_list->outfile_fd_r[j] = open
		(m_list->outfile_r[j], O_WRONLY | O_CREAT | O_TRUNC, 0774);
	if (j == l - 1)
		dup2(m_list->outfile_fd_r[j], 1);
	close(m_list->outfile_fd_r[j]);
	close(m_list->outfile_fd_l[j]);
}

void	calloc_outfile_norm(t_main_list **m_list)
{
	(*m_list)->outfile_r = calloc(token_count(\
		(*m_list), ">") + 1, sizeof(char *));
	(*m_list)->outfile_l = calloc(token_count(\
		(*m_list), ">") + 1, sizeof(char *));
	(*m_list)->outfile_fd_l = calloc(token_count(\
		(*m_list), ">") + 1, sizeof(int));
	(*m_list)->outfile_fd_r = calloc(token_count(\
		(*m_list), ">") + 1, sizeof(int));
}

void	out_dup2_error(t_main_list *m_list, int j, int l)
{
	if (m_list->outfile_l[j] && access(m_list->outfile_l[j], F_OK)
		&& ft_strcmp(m_list->outfile_l[j], m_list->cmd)
		&& ft_strcmp("echo", m_list->cmd)
		&& ft_strcmp(m_list->outfile_l[j], m_list->flag))
		print_error();
	else
		outfile_dup2(m_list, j, l);
}

void	outfile_fd(t_main_list *m_list, int l, int i, int j)
{
	if (!j)
		calloc_outfile_norm(&m_list);
	while (m_list->tdm[++i])
	{
		if (!ft_strcmp(m_list->tdm[i], ">"))
		{
			i++;
			if (i - 3 >= 0 && m_list->tdm[i - 3]
				&& !fix_cmp(m_list->tdm[i - 3], "<<"))
				m_list->outfile_l[j] = ft_strdup(".heredoc");
			else if (fix_cmp(m_list->flag, m_list->tdm[i - 2]))
				m_list->outfile_l[j] = ft_strdup(m_list->tdm[0]);
			else if (m_list->tdm[i - 2]
				&& (fix_cmp(m_list->cmd, m_list->tdm[i - 2])
					|| fix_cmp(m_list->path, m_list->tdm[i - 2])))
					m_list->outfile_l[j] = ft_strdup(m_list->tdm[i - 2]);
			m_list->outfile_r[j] = ft_strdup(m_list->tdm[i]);
			out_dup2_error(m_list, j, l);
			j++;
		}
	}
}

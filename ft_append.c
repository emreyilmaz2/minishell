/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:25:46 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 06:03:29 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* satir 40 > en sonda kapamak daha mantıklı 2 önceki fonksiyonda */
#include "minishell.h"

void	calloc_append_norm(t_main_list **m_list)
{
	(*m_list)->append_l = calloc
		(token_count((*m_list), ">>") + 1, sizeof(char *));
	(*m_list)->append_r = calloc
		(token_count((*m_list), ">>") + 1, sizeof(char *));
	(*m_list)->append_fd_l = calloc
		(token_count((*m_list), ">>") + 1, sizeof(int));
	(*m_list)->append_fd_r = calloc
		(token_count((*m_list), ">>") + 1, sizeof(int));
}

void	append_dup2(t_main_list *m_list, int j, int l)
{
	if (m_list->append_l[j])
		m_list->append_fd_l[j] = open(m_list->append_l[j], O_WRONLY, 0774);
	m_list->append_fd_r[j] = open
		(m_list->append_r[j], O_WRONLY | O_CREAT | O_APPEND, 0774);
	if (j == l -1)
		dup2(m_list->append_fd_r[j], 1);
	close(m_list->append_fd_l[j]);
	close(m_list->append_fd_r[j]);
}

void	app_dup2_error(t_main_list *m_list, int j, int l)
{
	if (m_list->append_l[j] && access(m_list->append_l[j], F_OK)
		&& ft_strcmp(m_list->append_l[j], m_list->cmd)
		&& ft_strcmp("echo", m_list->cmd)
		&& ft_strcmp(m_list->append_l[j], m_list->flag))
		print_error();
	else
		append_dup2(m_list, j, l);
}

void	append_fd(t_main_list *m_list, int l, int i, int j)
{
	if (!j)
		calloc_append_norm(&m_list);
	while (m_list->tdm[++i])
	{
		if (!ft_strcmp(m_list->tdm[i], ">"))
		{
			i++;
			if (i - 3 >= 0 && m_list->tdm[i - 3]
				&& !fix_cmp(m_list->tdm[i - 3], "<<"))
				m_list->append_l[j] = ft_strdup(".heredoc");
			else if (fix_cmp(m_list->flag, m_list->tdm[i - 2]))
				m_list->append_l[j] = ft_strdup(m_list->tdm[0]);
			else if (m_list->tdm[i - 2]
				&& (fix_cmp(m_list->cmd, m_list->tdm[i - 2])
					|| fix_cmp(m_list->path, m_list->tdm[i - 2])))
					m_list->append_l[j] = ft_strdup(m_list->tdm[i - 2]);
			m_list->append_r[j] = ft_strdup(m_list->tdm[i]);
			app_dup2_error(m_list, j, l);
			j++;
		}
	}
}

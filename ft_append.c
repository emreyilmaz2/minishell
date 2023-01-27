/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:25:46 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/25 09:31:04 by emyilmaz         ###   ########.fr       */
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
	dup2(m_list->append_fd_r[j], 1);
	close(m_list->append_fd_l[j]);
	close(m_list->append_fd_r[j]);
}
void	one_append(t_main_list **m_list)
{
	(*m_list)->append_fd_r[0] = open((*m_list)->append_r[0], \
		O_WRONLY | O_CREAT | O_TRUNC, 0774);
	dup2((*m_list)->append_fd_r[0],1);
	close((*m_list)->append_fd_l[0]);
}
void	append_fd(t_main_list *m_list)
{
	int (i) = -1;
	int (j) = 0;
	int (l) = token_count(m_list, ">>");
	if (!j)
		calloc_append_norm(&m_list);
	while (m_list->two_d_cmd[++i])
	{
		if (!ft_strcmp(m_list->two_d_cmd[i], ">>"))
		{
			i++;
			if(m_list->two_d_cmd[i-2])
				m_list->append_l[j] = ft_strdup(m_list->two_d_cmd[i - 2]);
			m_list->append_r[j] = ft_strdup(m_list->two_d_cmd[i]);
			if(!m_list->append_l[0] && m_list->append_r[0])
				one_append(&m_list);	
			else if (access(m_list->append_l[j], F_OK)
				&& ft_strcmp(m_list->append_l[j], m_list->cmd)
				&& ft_strcmp("echo", m_list->cmd))
				print_error();
			else
				append_dup2(m_list, j, l);
			j++;
		}
	}
}

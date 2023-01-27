/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:56:14 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/25 09:30:48 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_heredoc(t_main_list **m_list)
{
	char	*str;

	str = NULL;
	while (1)
	{
		write(1, "> ", 2);
		str = readline("");
		if (!ft_strcmp((*m_list)->eof, str))
			break ;
		write((*m_list)->eof_fd, str, ft_strlen(str));
		write((*m_list)->eof_fd, "\n", 1);
	}
	dup2((*m_list)->eof_fd, 0);
	close((*m_list)->eof_fd);
}

void	find_fd_eof(t_main_list **m_list)
{
	int (i) = 0;
		while ((*m_list)->two_d_cmd[i])
		{
			if (!ft_strcmp((*m_list)->two_d_cmd[i], (*m_list)->eof))
			{
				if (!access (".heredoc", F_OK))
					(*m_list)->eof_fd = open(".heredoc", O_WRONLY | O_TRUNC, 0774);
				else
					(*m_list)->eof_fd = open(".heredoc", O_WRONLY | O_CREAT, 0774);
			}
			i++;
		}
}

void	eof_fd(t_main_list *m_list)
{
	int (i) = 0;
	int (count) = 0;

	while (m_list->two_d_cmd[i])
	{
		if (!ft_strcmp(m_list->two_d_cmd[i], "<<"))
		{
			i++;
			m_list->eof = ft_strdup(m_list->two_d_cmd[i]);
			find_fd_eof(&m_list);
			fill_heredoc(&m_list);
				exit(0);
			}
		i++;
	}
}

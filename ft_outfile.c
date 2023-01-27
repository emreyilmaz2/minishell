/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:27:17 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/25 14:56:16 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	outfile_dup2(t_main_list *m_list, int j, int l)
{
if (m_list->outfile_name_l[j])
		m_list->outfile_fd_l[j] = open(m_list->outfile_name_l[j], O_WRONLY | O_CREAT, 0774);
	m_list->outfile_fd_r[j] = open
		(m_list->outfile_name_r[j], O_WRONLY | O_CREAT | O_TRUNC, 0774);
	dup2(m_list->outfile_fd_r[j], 1);
	close(m_list->outfile_fd_r[j]);
	close(m_list->outfile_fd_l[j]);
}

void	calloc_outfile_norm(t_main_list **m_list)
{
	(*m_list)->outfile_name_r = calloc(token_count(\
		(*m_list), ">") + 1, sizeof(char *));
	(*m_list)->outfile_name_l = calloc(token_count(\
		(*m_list), ">") + 1, sizeof(char *));
	(*m_list)->outfile_fd_l = calloc(token_count(\
		(*m_list), ">") + 1, sizeof(int));
	(*m_list)->outfile_fd_r = calloc(token_count(\
		(*m_list), ">") + 1, sizeof(int));
}
void one_outfile(t_main_list **m_list)
{
	(*m_list)->outfile_fd_r[0] = open((*m_list)->outfile_name_r[0], \
	O_WRONLY | O_CREAT | O_TRUNC, 0774);
	printf("---%d---\n", (*m_list)->outfile_fd_r[0]);
	dup2((*m_list)->outfile_fd_r[0],1);
	close((*m_list)->outfile_fd_r[0]);
	
}
void	outfile_fd(t_main_list *m_list, int l, int i, int j)
{
	int pid;
	l = token_count(m_list, ">");

	if (!j)
		calloc_outfile_norm(&m_list);
	while (m_list->two_d_cmd[++i])
	{
		if (!ft_strcmp(m_list->two_d_cmd[i], ">"))
		{
			i++;
			if(m_list->two_d_cmd[i-2])
				m_list->outfile_name_l[j] = ft_strdup(m_list->two_d_cmd[i - 2]);
			m_list->outfile_name_r[j] = ft_strdup(m_list->two_d_cmd[i]);
			printf("%s\n", m_list->outfile_name_r[j]);
			// pid = fork();
				if(!m_list->outfile_name_l[0] && m_list->outfile_name_r[0])
					one_outfile(&m_list);
				else if (access(m_list->outfile_name_l[j], F_OK)
					&& ft_strcmp(m_list->outfile_name_l[j], m_list->cmd)
					&& ft_strcmp("echo", m_list->cmd) && ft_strcmp(m_list->outfile_name_l[j], m_list->flag))
						print_error();
				else 
					outfile_dup2(m_list, j, l);
		j++;
		}
	}
}


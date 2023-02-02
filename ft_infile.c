/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:27:09 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 02:05:49 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	calloc_infile_norm(t_main_list **m_list)
{
	(*m_list)->infile_name_l = calloc(\
		token_count((*m_list), "<") + 1, sizeof(char *));
	(*m_list)->infile_name_r = calloc(\
		token_count((*m_list), "<") + 1, sizeof(char *));
	(*m_list)->infile_fd_l = calloc(\
		token_count((*m_list), "<") + 1, sizeof(int));
	(*m_list)->infile_fd_r = calloc(\
		token_count((*m_list), "<") + 1, sizeof(int));
}

void	infile_fd(t_main_list *m_list, int i, int j)
{
	if (!j)
		calloc_infile_norm(&m_list);
	while (m_list->tdm[++i])
	{
		if (!ft_strcmp(m_list->tdm[i], "<"))
		{
			i++;
			m_list->infile_name_l[j] = ft_strdup(m_list->tdm[i - 2]);
			m_list->infile_name_r[j] = ft_strdup(m_list->tdm[i]);
			if (access(m_list->infile_name_r[j], F_OK))
				print_error();
			j++;
		}
	}
}

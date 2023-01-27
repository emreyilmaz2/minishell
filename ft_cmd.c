/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataskin <ataskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:25:54 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/25 06:50:57 by ataskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	trying_find_cmd(t_main_list **m_list, char ***all_path)
{
	int (j) = -1;
	int (k) = -1;
	while (all_path[++k])
	{
		j = -1;
		while (all_path[k][++j])
		{
			if (!access(all_path[k][j], F_OK)
			&& ft_strcmp((*m_list)->two_d_cmd[j], "..")
			&& ft_strcmp((*m_list)->two_d_cmd[j], "."))
			{
				(*m_list)->cmd = ft_strdup((*m_list)->two_d_cmd[j]);
				(*m_list)->path = ft_strdup(all_path[k][j]);
			}
		}
	}
}

void	fill_it_all(char **array, char ****all_path, t_main_list *m_list)
{
	char	*src;

	int (j) = -1;
	int (k) = -1;
	while (array[++k])
	{
		j = -1;
		(*all_path)[k] = malloc(sizeof(char *) * \
			(twod_len(m_list->two_d_cmd) + 1));
		while (m_list->two_d_cmd[++j])
		{
			src = ft_strjoin("/", m_list->two_d_cmd[j]);
			(*all_path)[k][j] = ft_strjoin(array[k], src);
			free(src);
		}
		(*all_path)[k][j] = NULL;
	}
	(*all_path)[k] = NULL;
}

void check_array(t_main_list **m_list)
{
	int (j) = -1;
	while((*m_list)->two_d_cmd[++j])
	{
		if(!access((*m_list)->two_d_cmd[j],F_OK))
		{
			(*m_list)->path = ft_strdup((*m_list)->two_d_cmd[j]);
			(*m_list)->cmd = ft_strdup("doru"); 
			return ;
		}
	}
}
void	find_cmd(t_main_list *m_list)
{
	char	***all_path;
	char	*path;
	char	**array;

	all_path = NULL;
	m_list->cmd = NULL;
	path = getenv("PATH");
	array = ft_split(path, ':');
	all_path = malloc((sizeof(char **) * twod_len(array) \
			* twod_len(m_list->two_d_cmd) + 1));
	fill_it_all(array, &all_path, m_list);
	trying_find_cmd(&m_list, all_path);
	three_d_free(all_path);
	two_d_free(array);
	if(!m_list->cmd)
		check_array(&m_list);
}

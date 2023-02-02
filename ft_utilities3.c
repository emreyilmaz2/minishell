/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 04:53:39 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 02:40:56 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_initialize(t_main_list *temp)
{
	temp->path = NULL;
	temp->args = NULL;
	temp->eof = NULL;
	temp->pipe_cmd = NULL;
	temp->append_r = NULL;
	temp->append_l = NULL;
	temp->append_fd_l = NULL;
	temp->append_fd_r = NULL;
	temp->tdm = NULL;
	temp->outfile_r = NULL;
	temp->outfile_l = NULL;
	temp->outfile_fd_r = 0;
	temp->outfile_fd_l = 0;
	temp->infile_name_l = NULL;
	temp->infile_name_r = NULL;
	temp->flag = NULL;
	temp->cmd = NULL;
	temp->infile_fd_r = 0;
	temp->infile_fd_l = 0;
}

int	ft_checkset(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index++] == c)
			return (1);
	}
	return (0);
}

void	free_stack(t_mini *stack)
{
	t_mini	*tmp;
	t_mini	*delete;

	tmp = stack;
	while (tmp)
	{
		delete = tmp;
		tmp = tmp->next;
		free(delete->data);
		free(delete);
	}
}

int	fix_cmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (1);
	if (!s2)
		return (1);
	while (s1[i] && s2[i] && s2[i] == s1[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_dquote(char *str)
{
	if (ft_strchr(str, 39))
	{
		if (ft_strchr(str, 34))
		{
			if (ft_findlen(str, 34) < ft_findlen(str, 39))
				return (1);
			return (0);
		}
		return (0);
	}
	else
		return (1);
}

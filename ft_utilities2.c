/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:31:52 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/30 21:43:39 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	multi_close(t_main_list *m_list)
{
	int (out) = 0;
	int (app) = 0;
	while (m_list)
	{
		out = token_count(m_list, ">");
		app = token_count(m_list, ">>");
		while (m_list->append_fd_r[--app])
			close(m_list->append_fd_r[app]);
		app = token_count(m_list, ">>") - 1;
		while (m_list->outfile_fd_r[--app])
			close(m_list->outfile_fd_r[app]);
		out = token_count(m_list, ">");
		while (m_list->append_fd_l[--out])
			close(m_list->append_fd_l[out]);
		out = token_count(m_list, ">");
		while (m_list->outfile_fd_r[--out])
			close(m_list->outfile_fd_r[out]);
		m_list = m_list->next;
	}
}

void	print_list(t_mini *sadi)
{
	if (!sadi)
		return ;
	while (sadi->prev)
		sadi = sadi->prev;
	while (sadi != NULL)
	{
		printf("%s\n", sadi->data);
		sadi = sadi->next;
	}
}

t_mini	*build_list(char **string, t_mini *list)
{
	t_mini *(tmp) = NULL;
	t_mini *(list_two) = list;
	int (i) = 0;
	int (j) = -1;
	list->data = NULL;
	list->data = malloc(ft_strlen(string[i]) + 1);
	while (string[i][++j])
		list->data[j] = string[i][j];
	list->data[j] = '\0';
	list->next = NULL;
	list->prev = NULL;
	while (string[++i] != NULL)
	{
		list->next = malloc(sizeof(t_mini));
		tmp = list;
		list = list->next;
		list->prev = tmp;
		list->data = malloc(ft_strlen(string[i]) + 1);
		j = -1;
		while (string[i][++j])
			list->data[j] = string[i][j];
		list->data[j] = '\0';
		list->next = NULL;
	}
	return (list_two);
}

int	token_count(t_main_list *m_list, char *delimeter)
{
	int (i) = 0;
	int (len) = 0;
	while (m_list->tdm[i])
	{
		if (!ft_strcmp(m_list->tdm[i], delimeter))
			len++;
		i++;
	}
	return (len);
}

int	any_pipe(t_mini *list)
{
	while (list)
	{
		if (ft_strchr(list->data, '|'))
			return (1);
		list = list->next;
	}
	return (0);
}

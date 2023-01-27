/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataskin <ataskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:25:57 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/25 07:05:16 by ataskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	no_greens(t_mini ***lst2)
{
	char	*arr;

	arr = ft_strdup((**lst2)->data);
	free((**lst2)->data);
	(**lst2)->data = ft_strtrim2(arr, 34);
	free(arr);
}

void	check_greens(t_mini **lst2, t_expander **exp)
{
	int (i) = -1;
	int (j) = 0;
	if (ft_strchr((*lst2)->data, '$'))
	{
		(*exp)->temp_head = ft_substr((*lst2)->data, 0, \
		ft_findlen((*lst2)->data, '$'));
		j = ft_findlen((*lst2)->data, '$');
		j++;
		while ((*exp)->env_head[++i])
		{
			if (ft_str_in_str((*lst2)->data, j, (*exp)->env_head[i]))
			{
				(*exp)->temp = ft_strdup((*exp)->env_tail[i]);
				(*exp)->temp_tail = ft_substr((*lst2)->data, j + \
				ft_strlen((*exp)->env_head[i]), ft_strlen((*lst2)->data));
			}
			expander_trim_dquote(&lst2, &exp);
		}
	}
	else
		no_greens(&lst2);
}

void	expander_uptade(t_mini *lst2, t_expander *exp)
{
	char	*arr;

	int (k) = 0;
	exp->temp = NULL ;
	exp->temp_tail = NULL ;
	exp->temp_head = NULL ;
	if (check_dquote(lst2->data))
		check_greens(&lst2, &exp);
	else
		expander_trim_squote(&lst2, &exp);
}

void	head_and_tail(t_expander *expander)
{
	int (i) = 0;
	expander->temp = NULL ;
	expander->temp_tail = NULL ;
	expander->temp_head = NULL ;
	expander->env_head = NULL ;
	expander->env_tail = NULL ;
	expander->env_head = calloc(sizeof(char *), \
	(ft_two_dim_len(g_list->environment) + 1));
	expander->env_tail = calloc(sizeof(char *), \
	(ft_two_dim_len(g_list->environment) + 1));
	while (g_list->environment[i])
	{
		expander->env_head[i] = ft_substr(g_list->environment[i], 0, \
			ft_findlen(g_list->environment[i], '='));
		expander->env_tail[i] = ft_substr(g_list->environment[i], \
		ft_findlen(g_list->environment[i], '=') + 1, \
		ft_strlen(g_list->environment[i]) - ft_findlen(g_list->environment[i], '='));
		i++;
	}
}

t_expander	*expander(t_mini *list)
{	
	t_expander	*expander;

	int (i) = 1;
	int (j) = 0;
	expander = malloc(sizeof(t_expander));
	head_and_tail(expander);
	while (list)
	{
		expander_uptade(list, expander);
		if (expander->temp)
			free(expander->temp);
		if (expander->temp_head)
			free(expander->temp_head);
		if (expander->temp_tail)
			free(expander->temp_tail);
		list = list->next;
	}
	return (expander);
}

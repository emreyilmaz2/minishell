/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:25:57 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 00:28:58 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_greens(t_mini **lst2, t_expander **exp, int j)
{
	int (i) = -1;
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
			else if ((*lst2)->data[j] == '?')
				ft_expand_dollar(&exp, lst2, &j);
			expander_trim_dquote(&lst2, &exp);
		}
	}
	else
		no_greens(&lst2);
}

void	ft_expand_dollar(t_expander ***exp, t_mini **lst2, int *j)
{
	char *(temporary);
	temporary = ft_itoa(g_list->exit_status);
	(**exp)->temp = ft_strdup(temporary);
	(**exp)->temp_tail = ft_substr((*lst2)->data, *j + \
	ft_strlen(temporary), 4);
	(*j)++;
	free(temporary);
}

void	expander_uptade(t_mini *lst2, t_expander *exp)
{
	exp->temp = NULL ;
	exp->temp_tail = NULL ;
	exp->temp_head = NULL ;
	if (check_dquote(lst2->data))
		check_greens(&lst2, &exp, 0);
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
	(ft_size_array(g_list->environment) + 1));
	expander->env_tail = calloc(sizeof(char *), \
	(ft_size_array(g_list->environment) + 1));
	while (g_list->environment[i])
	{
		expander->env_head[i] = ft_substr(g_list->environment[i], 0, \
			ft_findlen(g_list->environment[i], '='));
		expander->env_tail[i] = ft_substr(g_list->environment[i], \
		ft_findlen(g_list->environment[i], '=') + 1, \
		ft_strlen(g_list->environment[i]) - \
			ft_findlen(g_list->environment[i], '='));
		i++;
	}
}

t_expander	*expander(t_mini *list)
{	
	t_expander	*expander;

	expander = ft_calloc(sizeof(t_expander), 1);
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

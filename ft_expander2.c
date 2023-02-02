/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:25:59 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/30 04:37:04 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expander_trim_dquote(t_mini ***list_two, t_expander ***exp)
{
	char	*arr;

	(**exp)->src = NULL;
	if ((**exp)->temp)
	{
		expander_trim_dquote_norm(&exp, &arr);
		if ((**exp)->temp_head[0] == 34)
		{
			arr = ft_strdup((**exp)->src);
			free((**exp)->src);
		(**exp)->src = ft_strtrim2(arr, 34);
			free(arr);
		}
		free((**list_two)->data);
		(**list_two)->data = ft_strdup((**exp)->src);
		free((**exp)->src);
	}
}

void	expander_trim_dquote_norm(t_expander ****exp, char **arr)
{
	if (((***exp)->temp_head) && (***exp)->temp_tail)
	{
		(*arr) = ft_strjoin((***exp)->temp_head, (***exp)->temp);
		(***exp)->src = ft_strjoin((*arr), (***exp)->temp_tail);
		free((*arr));
	}
	else if ((***exp)->temp_head && (***exp)->temp_tail)
	(***exp)->src = ft_strjoin((***exp)->temp, (***exp)->temp_tail);
	else if ((***exp)->temp_head && (***exp)->temp_tail)
	(***exp)->src = ft_strdup((***exp)->temp);
	else if ((***exp)->temp_head && (***exp)->temp_tail)
	(***exp)->src = ft_strdup((***exp)->temp_head);
}

void	expander_trim_squote(t_mini **list_two, t_expander **expander)
{
	(*expander)->src = NULL ;
	(*expander)->src = ft_strtrim2((*list_two)->data, 39);
	free((*list_two)->data);
	(*list_two)->data = ft_strdup((*expander)->src);
	free((*expander)->src);
}

void	no_greens(t_mini ***lst2)
{
	char	*arr;

	arr = ft_strdup((**lst2)->data);
	free((**lst2)->data);
	(**lst2)->data = ft_strtrim2(arr, 34);
	free(arr);
}

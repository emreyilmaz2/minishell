/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:58:50 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/24 19:01:06 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_compare(char *str, int i)
{
	if (str[i] == '<' && str[i + 1] == '<')
		return (0);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (0);
	else if (str[i] == '<')
		return (0);
	else if (str[i] == '>')
		return (0);
	else if (str[i] == '|')
		return (0);
	return (1);
}

char	**ft_array_copy_stuff(char *array, char **temp, int *y, int flag)
{
	if (array[0])
	{
		temp[*y] = malloc(sizeof(char) * ft_strlen(array) + 1);
		ft_strlcpy(temp[*y], array, ft_strlen(array) + 1);
		(*y)++;
	}
	if (flag == 99)
		free(array);
	return (temp);
}

char	**ft_character_copy_stuff(char **temp, char *str, int *i, int *y)
{
	if ((str[*i] == '<' && str[*i + 1] == '<')
		|| (str[*i] == '>' && str[*i + 1] == '>'))
	{
		temp[*y] = malloc(sizeof(char) * 3);
		temp[*y][0] = str[*i];
		temp[*y][1] = str[*i + 1];
		temp[*y][2] = '\0';
		(*i) += 2;
		(*y)++;
	}
	else
	{
		temp[*y] = malloc(sizeof(char) * 2);
		temp[*y][0] = str[*i];
		temp[*y][1] = '\0';
		(*y)++;
		(*i)++;
	}
	return (temp);
}

char	**monster_truck(char *str, int i, int j, int y)
{
	char	**temp;
	char	*array;

	int (flag) = 0;
	array = ft_calloc(50, sizeof(char));
	temp = ft_calloc(counter(str) + 2, sizeof(char *));
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			flag++;
		if (!ft_compare(str, i) && flag % 2 == 0)
		{
			temp = ft_array_copy_stuff(array, temp, &y, 0);
			temp = ft_character_copy_stuff(temp, str, &i, &y);
			ft_memset(array, 0, sizeof(array));
			j = 0;
		}
		else
			array[j++] = str[i++];
	}
	temp = ft_array_copy_stuff(array, temp, &y, 9);
	free(array);
	return (temp);
}

char	**this_is_not_split(char **string, int len, int j, int r)
{
	char	**temp;
	char	**daft;

	int (i) = -1;
	temp = ft_calloc(sizeof(char *), len + 2);
	while (string[++i])
	{
		if (!ft_check_quotes(string[i]) && (ft_strchr(string[i], '<') || \
			ft_strchr(string[i], '>') || ft_strchr(string[i], '|')))
		{
			daft = monster_truck(string[i], 0, 0, 0);
			r = -1;
			while (daft[++r])
				temp = temproray_copy(&temp, daft, r, &j);
			two_d_free(daft);
		}
		else
		{
			temp[++j] = malloc(sizeof(char) * ft_strlen(string[i]) + 1);
			ft_strlcpy(temp[j], string[i], ft_strlen(string[i]) + 1);
		}
	}
	return (temp);
}

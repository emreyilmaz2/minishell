/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 04:08:58 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/30 22:20:11 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	two_d_free(char **str)
{
	int (i) = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

void	free_data(t_data *can)
{
	if (can->str)
		two_d_free(can->str);
	if (can->data)
		free(can->data);
	if (can)
		free(can);
}

void	three_d_free(char ***str)
{
	int (i) = -1;
	int (j) = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			free(str[i][j]);
		}
		free(str[i]);
	}
	free(str);
}

int	ft_findlen(const char *s, char c)
{
	int (i) = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (0);
}

int	ft_size_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

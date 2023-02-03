/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_and_export2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:20:58 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 06:33:47 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_check(char *ptr)
{
	char	*temp1;
	char	*temp2;

	int (i)[3] = {0, 0, 0};
	while (ptr[i[2]] && ptr[i[2]] != '=')
		i[2]++;
	temp1 = ft_substr(ptr, 0, i[2]);
	while ((i[0] < g_list->sayac && g_list->environment[i[0]]))
	{
		i[1] = 0;
		while (g_list->environment[i[0]][i[1]] != '='
			&& g_list->environment[i[0]][i[1]])
			i[1]++;
		temp2 = ft_substr(g_list->environment[i[0]], 0, i[1]);
		if (!ft_strcmp(temp1, temp2))
		{
			free(temp2);
			free(temp1);
			return (i[0]);
		}
		i[0]++;
		free(temp2);
	}
	free(temp1);
	return (-1);
}

int	export_check(char *ptr)
{
	char	*temp1;
	char	*temp2;

	int (i)[3] = {0, 0, 0};
	while (ptr[i[2]] && ptr[i[2]] != '=')
		i[2]++;
	temp1 = ft_substr(ptr, 0, i[2]);
	while (g_list->export[i[0]])
	{
		i[1] = 0;
		while (g_list->export[i[0]][i[1]] != '=' && g_list->export[i[0]][i[1]])
			i[1]++;
		temp2 = ft_substr(g_list->export[i[0]], 0, i[1]);
		if (!ft_strcmp(temp1, temp2))
		{
			free(temp2);
			free(temp1);
			return (i[0]);
		}
		i[0]++;
		free(temp2);
	}
	free(temp1);
	return (-1);
}

void	ft_env(void)
{
	int (j) = -1;
	while (g_list->environment[++j] && j < g_list->sayac)
		printf("%s\n", g_list->environment[j]);
}

void	ft_pwd(t_expander *exp)
{
	char	*arr;

	arr = NULL;
	int (j) = -1;
	while (exp->env_head[++j])
	{
		if (!ft_strcmp(exp->env_head[j], "PWD"))
		{
			arr = ft_strdup(exp->env_tail[j]);
			break ;
		}
	}
	printf("%s\n", arr);
	free(arr);
}

char	*get_env_before_equal(char *ptr)
{
	char	*temp;

	int (i) = 0;
	while (ptr[i] != '=')
		i++;
	temp = ft_substr(ptr, 0, i);
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_some_bultins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:26:16 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/30 23:19:01 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_main_list *m_list)
{
	char **(arr) = ft_calloc(sizeof(char *),
			ft_size_array(m_list->args));
	int (im)[3] = {0, 0, 0};
	if (m_list->args[im[0]] && !m_list->args[im[0] + 1])
		return (printf("\n"));
	while (m_list->args[im[0]])
	{
		if (!fix_cmp(m_list->args[im[0]], m_list->cmd))
			im[0]++;
		arr[im[2]++] = ft_strdup(m_list->args[im[0]]);
		im[0]++;
	}
	im[0] = -1;
	while (++im[0] < im[2])
	{
		if (!ft_strcmp(arr[im[0]], "-n"))
			im[1] = 1;
		else if (im[0] + 1 != im[2])
			printf("%s ", arr[im[0]]);
		else
			printf("%s", arr[im[0]]);
	}
	if (im[1] == 0)
		printf("\n");
	return (two_d_free(arr));
}

void	ft_exit(t_main_list *m_list)
{
	if (m_list->args[1] && is_numeric(m_list->args[1]))
	{
		printf("bash: exit: %s: numeric argument required\n", m_list->args[1]);
		exit(g_list->exit_status = 255);
	}
	else if (m_list->args[1] && !is_numeric(m_list->args[1]))
		exit(g_list->exit_status = ft_atoi(m_list->args[1]) % 255 - 1);
	else if (ft_size_array(m_list->args) > 2 && !is_numeric(m_list->args[1]))
	{
		printf("bash: exit: too many arguments\n");
		g_list->exit_status = 1;
	}
	else if (ft_size_array(m_list->args) == 2)
	{
		if (ft_atoi(m_list->args[1]) > 255)
			exit(g_list->exit_status = ft_atoi(m_list->args[1]) % 255 - 1);
		else if (ft_atoi(m_list->args[1]) > 255)
			exit(g_list->exit_status = ft_atoi(m_list->args[1]));
	}
	else
		exit(g_list->exit_status = 0);
}

int	is_all_numeric(char **argv)
{
	int (i) = 1;
	int (j) = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') && argv[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_numeric(char *argv)
{
	int (j) = 1;
	while (argv[j])
	{
		if (!(argv[j] >= '0' && argv[j] <= '9') && argv[j])
			return (1);
		j++;
	}
	return (0);
}

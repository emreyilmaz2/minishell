/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_dir_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:15:05 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 06:15:17 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_after_equal(char *ptr)
{
	char	*temp;

	int (i) = 0;
	while (ptr[i] != '=')
		i++;
	temp = ft_substr(ptr, i + 1, ft_strlen(ptr));
	return (temp);
}

char	*get_env_previous_slash(char *ptr)
{
	int		i;

	i = ft_strlen(ptr);
	while (ptr[--i])
	{
		if (ptr[i] == '/')
			break ;
	}
	return (ft_substr(ptr, 0, i));
}

char	*ft_after_last_slash(char *ptr)
{
	int		i;

	i = ft_strlen(ptr);
	while (ptr[--i])
	{
		if (ptr[i] == '/')
			break ;
	}
	return (ft_substr(ptr, i + 1, ft_strlen(ptr)));
}

int	is_builtin2(t_main_list *m_list)
{
	return (!ft_strcmp(m_list->args[0], "env")
		| !ft_strcmp(m_list->args[0], "exit")
		| !ft_strcmp(m_list->args[0], "unset")
		| !ft_strcmp(m_list->args[0], "export")
		| !ft_strcmp(m_list->args[0], "pwd")
		| !ft_strcmp(m_list->args[0], "cd"));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_and_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:02:05 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/27 18:42:15 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_main_list *m_list)
{
	int (line) = 0;
	int (i) = 0;

	if (!fix_cmp("unset", m_list->args[0]) && !m_list->args[1])
        return ;
	else if(!fix_cmp("unset", m_list->args[0]) && m_list->args[1])
	{
		line = env_check(m_list->args[1]);
		if(line > 0)
		{
			ft_unset_env(line);
			ft_unset_export(line);
		}
	}
}

void	ft_unset_env(int line)
{
	char **temp = calloc(sizeof(char *), 100);
	int i = 0;
    while(line != i && g_list->environment[i] && i < g_list->sayac)
    {
        temp[i] = ft_strdup(g_list->environment[i]);
        i++;
    }
    int j = i;
    i++;
    while(i < g_list->sayac && g_list->environment[i])
    {
        temp[j] = ft_strdup(g_list->environment[i]);
        j++;
        i++;
    }
    i = 0;
    while(temp[i])
    {
        free(g_list->environment[i]);
        g_list->environment[i] = ft_strdup(temp[i]);
        i++;
    }
    g_list->sayac--;
	two_d_free(temp);
}

void	ft_unset_export(int line)
{
	char **temp = calloc(sizeof(char *), 100);
	int (i) = -1;
	int t;
    while(++i >= 0 && line != i && g_list->export[i])
        temp[i] = ft_strdup(g_list->export[i]);
    int j = i;
    while(g_list->export[++i])
    {
        temp[j] = ft_strdup(g_list->export[i]);
        j++;
    }
    i = -1;
    while(temp[++i])
    {
        free(g_list->export[i]);
        g_list->export[i] = ft_strdup(temp[i]);
    }
	t = i;
    while(g_list->export[i])
    {
        free(g_list->export[i]);
        i++;
    }
	g_list->export[t] = NULL;
	two_d_free(temp);
}

void	ft_export(t_main_list *m_list)
{
	int (j) = -1;
	int (line) = 0;
	int (k) = 0;
	int (i) = 0;
	int (len) = -1;

	if (!fix_cmp("export", m_list->args[0]) && !m_list->args[1])
	{
		while (g_list->export[++j])
			printf("declare -x %s\n", g_list->export[j]);
	}
	else if(!fix_cmp("export", m_list->args[0]) && ft_strchr(m_list->args[1], '='))
	{
		line = env_check(m_list->args[1]);
		if(line > 0)
		{
			free(g_list->environment[line]);
			g_list->environment[line] = ft_strdup(m_list->args[1]);
			free(g_list->export[line]);
			g_list->export[line] = ft_strdup(m_list->args[1]);
		}
		else
		{
			if(g_list->environment[g_list->sayac])
				free(g_list->environment[g_list->sayac]);
			g_list->environment[g_list->sayac++] = ft_strdup(m_list->args[1]);
			k = twod_len(g_list->export);
			g_list->export[k] = ft_strdup(m_list->args[1]);
		}
	}
	else
	{
		k = twod_len(g_list->export);
		g_list->export[k] = ft_strdup(m_list->args[1]);
	}
}

int	env_check(char *ptr)
{
	int (i) = 0;
	int (j) = 0;
	int (len) = 0;
	char *temp1;
	char *temp2;

	while (ptr[len] && ptr[len] != '=')
		len++;
	temp1 = ft_substr(ptr, 0, len);
	while(i < g_list->sayac && g_list->environment[i])
	{
		j = 0;
		while (g_list->environment[i][j] != '=' && g_list->environment[i][j])
			j++;
		temp2 = ft_substr(g_list->environment[i], 0, j);
		if(!ft_strcmp(temp1, temp2))
		{
			free(temp2);
			free(temp1);
			return(i);
		}
		i++;
		free(temp2);
	}
	free(temp1);
	return(-1);
}

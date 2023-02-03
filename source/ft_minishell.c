/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 06:16:52 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 00:48:26 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*g_list;

int	get_readline(t_data *can, int temp_fd)
{
	size_t (i) = 0;
	dup2(temp_fd, 0);
	can->data = readline(g_list->name);
	if (!can->data)
		exit(1);
	while (can->data[i] <= 32 && can->data[i])
		i++;
	if (ft_strlen(can->data) == i)
		return (1);
	if (ft_strcmp(can->data, ""))
		add_history(can->data);
	return (0);
}

void	ft_loop(t_main_list *m_l, t_mini *list, int t, t_data *can)
{
	int (fd_tmp) = dup(1);
	int (temp_fd) = dup(0);
	while (1)
	{
		g_list->f = 1;
		can = malloc(sizeof(t_data));
		can->str = NULL;
		ft_signal();
		t = get_readline(can, temp_fd);
		if (ft_strcmp(can->data, "") && check_input(can->data) && !t)
		{
			list = lexer(can);
			if (check_list(list))
			{
				g_list->exp = expander(list);
				m_l = parser(list, NULL);
				if (g_list->f)
					executer2(&m_l, &list, &fd_tmp);
			}
			multi_free(m_l, list, g_list->exp);
		}
		free_data(can);
	}
}

void	executer2(t_main_list **m_l, t_mini **list, int *fd_tmp)
{
	executer((*m_l), (*list), g_list->exp, (*fd_tmp));
	dup2((*fd_tmp), 1);
	multi_close((*m_l));
}

int	main(int argc, char **argv, char **env)
{
	t_main_list *(m_l) = NULL;
	t_mini *(list) = NULL;
	t_data *(can) = NULL;
	(void)argc;
	(void)argv;
	int (i) = -1;
	int (t) = 0;
	g_list = malloc(sizeof(t_env));
	g_list->environment = ft_calloc(sizeof(char *), 100);
	while (env[++i])
		g_list->environment[i] = ft_strdup(env[i]);
	g_list->sayac = ft_size_array(g_list->environment);
	g_list->name = ft_strdup("\033[0;34m@minishell-> \033[0m");
	g_list->export = ft_calloc(sizeof(char *), 100);
	i = -1;
	while (env[++i])
		g_list->export[i] = ft_strdup(env[i]);
	ft_loop(m_l, list, t, can);
	two_d_free(g_list->export);
	two_d_free(g_list->environment);
	free(g_list->name);
	free(g_list);
	return (0);
}

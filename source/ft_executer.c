/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:18:31 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 06:10:28 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	which_buildin(t_main_list *m_list, t_expander *exp)
{
	if (!ft_strcmp(m_list->args[0], "echo"))
		ft_echo(m_list);
	else if (!ft_strcmp(m_list->args[0], "cd"))
		ft_cd(m_list);
	else if (!ft_strcmp(m_list->args[0], "pwd"))
		ft_pwd(exp);
	else if (!ft_strcmp(m_list->args[0], "export"))
		ft_export(m_list);
	else if (!ft_strcmp(m_list->args[0], "unset"))
		ft_unset(m_list);
	else if (!ft_strcmp(m_list->args[0], "env"))
		ft_env();
	else if (!ft_strcmp(m_list->args[0], "exit"))
		ft_exit(m_list);
	else
		return ;
}

int	is_builtin(t_main_list *m_list)
{
	return (!ft_strcmp(m_list->args[0], "env")
		| !ft_strcmp(m_list->args[0], "exit")
		| !ft_strcmp(m_list->args[0], "unset")
		| !ft_strcmp(m_list->args[0], "export")
		| !ft_strcmp(m_list->args[0], "pwd")
		| !ft_strcmp(m_list->args[0], "cd")
		| !ft_strcmp(m_list->args[0], "echo"));
}

int	is_builtin3(t_main_list *m_list)
{
	return (!ft_strcmp(m_list->tdm[0], "env")
		| !ft_strcmp(m_list->tdm[0], "exit")
		| !ft_strcmp(m_list->tdm[0], "unset")
		| !ft_strcmp(m_list->tdm[0], "export")
		| !ft_strcmp(m_list->tdm[0], "pwd")
		| !ft_strcmp(m_list->tdm[0], "cd")
		| !ft_strcmp(m_list->tdm[0], "echo"));
}

void	execute(int tmp_fd, t_main_list *m_list)
{
	int (err) = 0;
	dup2(tmp_fd, 0);
	close(tmp_fd);
	if (is_builtin(m_list))
		which_buildin(m_list, NULL);
	else
		err = execve(m_list->path, m_list->args, g_list->environment);
	if (err == -1)
	{
		printf("minishell: command not found: %s\n", m_list->args[0]);
		g_list->exit_status = 127;
	}
	else
		g_list->exit_status = 0;
}

void	executer(t_main_list *m_list, t_mini *list, t_expander *exp, int fd_tmp)
{
	int *(fd) = malloc(sizeof(int) * 2);
	int (tmp_fd) = dup(0);
	int (flag) = 0;
	while (m_list)
	{
		pipe(fd);
		if (!any_pipe(list) && is_builtin2(m_list))
			which_buildin(m_list, exp);
		else if (m_list && !m_list->next && !flag)
			run_executer_zero(&tmp_fd, m_list);
		else if ((m_list->next && (ft_str_in_str2(m_list->pipe_cmd, "<<")
					|| ft_str_in_char(m_list->pipe_cmd, '>')))
			|| (m_list && !m_list->next
				&& (ft_str_in_str2(m_list->pipe_cmd, "<<")
					|| ft_str_in_char(m_list->pipe_cmd, '>'))))
			run_executer_one(&fd, &tmp_fd, m_list);
		else if (m_list->next)
			run_executer_two(&fd, &tmp_fd, m_list);
		else
			run_executer_three(&fd_tmp, &tmp_fd, m_list);
		flag++;
		m_list = m_list->next;
	}
	free(fd);
}

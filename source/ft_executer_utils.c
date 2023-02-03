/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 06:02:50 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 06:06:22 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_executer_zero(int *tmp_fd, t_main_list *m_list)
{
	if (fork() == 0)
	{
		execute((*tmp_fd), m_list);
		exit(0);
	}
	else
	{
		close((*tmp_fd));
		while (waitpid(-1, NULL, WUNTRACED) != -1)
			;
		(*tmp_fd) = dup(0);
	}
}

void	run_executer_one(int **fd, int *tmp_fd, t_main_list *m_list)
{
	if (fork() == 0)
	{
		close((*fd)[0]);
		close((*fd)[1]);
		execute((*tmp_fd), m_list);
		exit(0);
	}
	else
	{
		close((*fd)[1]);
		close((*tmp_fd));
		(*tmp_fd) = (*fd)[0];
	}
}

void	run_executer_two(int **fd, int *tmp_fd, t_main_list *m_list)
{
	if (fork() == 0)
	{
		dup2((*fd)[1], 1);
		close((*fd)[0]);
		close((*fd)[1]);
		execute((*tmp_fd), m_list);
		exit(0);
	}
	else
	{
		close((*fd)[1]);
		close((*tmp_fd));
		(*tmp_fd) = (*fd)[0];
	}
}

void	run_executer_three(int *fd_tmp, int *tmp_fd, t_main_list *m_list)
{
	if (fork() == 0)
	{
		dup2((*fd_tmp), 1);
		close((*fd_tmp));
		execute((*tmp_fd), m_list);
		exit(0);
	}
	else
	{
		close((*tmp_fd));
		while (waitpid(-1, NULL, WUNTRACED) != -1)
			;
		(*tmp_fd) = dup(0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_them_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:26:02 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 00:37:22 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_t_expander(t_expander *expr)
{
	if (expr->env_head)
		two_d_free(expr->env_head);
	if (expr->env_tail)
		two_d_free(expr->env_tail);
	if (expr)
		free(expr);
}

void	free_t_main1(t_main_list *lst)
{
	if (lst->path)
		free(lst->path);
	if (lst->pipe_cmd)
		free(lst->pipe_cmd);
	if (lst->infile_fd_l)
		free(lst->infile_fd_l);
	if (lst->infile_fd_r)
		free(lst->infile_fd_r);
	if (lst->infile_name_l)
		two_d_free(lst->infile_name_l);
	if (lst->infile_name_r)
		two_d_free(lst->infile_name_r);
	if (lst->append_r)
		two_d_free(lst->append_r);
	if (lst->append_l)
		two_d_free(lst->append_l);
	if (lst->append_fd_l)
		free(lst->append_fd_l);
	if (lst->append_fd_r)
		free(lst->append_fd_r);
	if (lst->outfile_fd_l)
		free(lst->outfile_fd_l);
	if (lst->outfile_fd_r)
		free(lst->outfile_fd_r);
}

void	free_t_main2(t_main_list *lst)
{
	if (lst->cmd)
		free(lst->cmd);
	if (lst->flag)
		free(lst->flag);
	if (lst->outfile_l)
		two_d_free(lst->outfile_l);
	if (lst->outfile_r)
		two_d_free(lst->outfile_r);
	if (lst->eof)
		free(lst->eof);
	if (lst->tdm)
		two_d_free(lst->tdm);
	if (lst->args)
		two_d_free(lst->args);
}

void	free_t_main(t_main_list *lst)
{
	t_main_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free_t_main1(tmp);
		free_t_main2(tmp);
		free(tmp);
	}
}

void	multi_free(t_main_list *m_l, t_mini *list, t_expander *exp)
{
	if (exp)
		free_t_expander(exp);
	if (list)
		free_stack(list);
	if (m_l)
		free_t_main(m_l);
}

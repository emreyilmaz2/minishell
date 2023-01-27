/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_them_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataskin <ataskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:26:02 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/25 02:43:43 by ataskin          ###   ########.fr       */
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
	if (lst->outfile_name_l)
		two_d_free(lst->outfile_name_l);
	if (lst->outfile_name_r)
		two_d_free(lst->outfile_name_r);
	if (lst->eof)
		free(lst->eof);
	if (lst->two_d_cmd)
		two_d_free(lst->two_d_cmd);
	if (lst->args)
		two_d_free(lst->args);
}

void	free_t_main(t_main_list *lst)
{
	t_main_list	*tmp;

	int (i) = 0;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free_t_main1(tmp);
		free_t_main2(tmp);
		free(tmp);
	}
}

void	multi_free(t_main_list *m_l, t_mini *list, t_expander *exp, t_data *can)
{
	free_t_expander(exp);
	free_stack(list);
	free_t_main(m_l);
	two_d_free(can->str);
}

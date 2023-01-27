/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:30:58 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/25 11:32:18 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void print_error()
{
	perror("No file or directory");
	signal_replace_line(SIGINT);
}

void args_infile(t_main_list **m_list, int *l, int *i)
{//pointer i'lerden hiç emin değilim
	int r;

	r = token_count((*m_list),"<");
	if(!fix_cmp((*m_list)->infile_name_l[0],(*m_list)->cmd))
	{
		(*m_list)->args[(*l)++] = ft_strdup((*m_list)->cmd);
		(*m_list)->args[(*l)++] = ft_strdup((*m_list)->infile_name_r[r-1]);
		(*i) += 2;
	}
	else
		(*m_list)->args[(*l)++] = ft_strdup((*m_list)->two_d_cmd[(*i)++]);
}
void compare_all(t_main_list **m_list, int *i, int *l)
{
	if(ft_compare_c((*m_list)->two_d_cmd[(*i)], (*m_list)))
		(*m_list)->args[(*l)++] = ft_strdup((*m_list)->two_d_cmd[(*i)++]);
	else
		(*i)++;
}
int operator_cmp(t_main_list *m_list, int i)
{
	if(!fix_cmp(m_list->two_d_cmd[i], "<"))
		return (1);
	else if(!fix_cmp(m_list->two_d_cmd[i],">"))
		return (1);
	else if(!fix_cmp(m_list->two_d_cmd[i],">>"))
		return (1);
	else if(!fix_cmp(m_list->two_d_cmd[i],"<<"))
		return (1);
	else if(!fix_cmp(m_list->two_d_cmd[i],"|"))
		return (1);
	return (0);
}
void all_args(t_main_list *m_list)
{
	int i = 0;
	int l = 0;
	int j = 0;
	m_list->args = calloc(sizeof(char *),1000);
	while(m_list->two_d_cmd[i])
	{
		if(!fix_cmp(m_list->flag,m_list->two_d_cmd[i]))
			m_list->args[l++] = ft_strdup(m_list->two_d_cmd[i++]);
		else if(!fix_cmp(m_list->infile_name_l[0],m_list->two_d_cmd[i]))
			args_infile(&m_list,&l,&i);
		else if(!fix_cmp(m_list->cmd,m_list->two_d_cmd[i]))
			m_list->args[l++] = ft_strdup(m_list->two_d_cmd[i++]);
		else if(!fix_cmp(m_list->append_l[0],m_list->two_d_cmd[i]))
				m_list->args[l++] = ft_strdup(m_list->two_d_cmd[i++]);
		else if(!fix_cmp(m_list->outfile_name_l[0],m_list->two_d_cmd[i]))
				m_list->args[l++] = ft_strdup(m_list->two_d_cmd[i++]);
		else if(operator_cmp(m_list,i))
			 i++;
		else if(!fix_cmp(m_list->eof,m_list->two_d_cmd[i]) && ((!m_list->two_d_cmd[4] && !fix_cmp(m_list->two_d_cmd[3],m_list->flag)) || (!m_list->two_d_cmd[3] && !fix_cmp(m_list->two_d_cmd[2],m_list->eof))))
		{
			m_list->args[l++] = ft_strdup(".heredoc");
			i++;
		}
		else if(!fix_cmp(m_list->eof,m_list->two_d_cmd[i]))
			i++;
		else
			compare_all(&m_list,&i,&l);
	}
}
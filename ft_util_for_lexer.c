/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_for_lexer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:29:00 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/30 23:54:36 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	counter(char *input)
{
	int (counter) = 0;
	int (i) = 0;
	while (input[i])
	{
		if (input[i] == '|')
			counter += left_right(input, &i, 0);
		else if (input[i] == '<' && input[i + 1] == '<')
			counter += left_right(input, &i, 2);
		else if (input[i] == '<')
			counter += left_right(input, &i, 0);
		else if (input[i] == '>' && input[i + 1] == '>')
			counter += left_right(input, &i, 2);
		else if (input[i] == '>')
			counter += left_right(input, &i, 0);
		else
			i++;
	}
	return (counter);
}

int	counter2(char **input)
{
	int (counter) = 0;
	int (i) = 0;
	int (j) = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (input[i][j] == '|')
				counter += left_right(input[i], &j, 0);
			else if (input[i][j] == '<' && input[i][j + 1] == '<')
				counter += left_right(input[i], &j, 2);
			else if (input[i][j] == '<')
				counter += left_right(input[i], &j, 0);
			else if (input[i][j] == '>' && input[i][j + 1] == '>')
				counter += left_right(input[i], &j, 2);
			else if (input[i][j] == '>')
				counter += left_right(input[i], &j, 0);
			else
				j++;
		}
		i++;
	}
	return (counter);
}

char	**temproray_copy(char ***temp, char **daft, int r, int *j)
{
	(*j)++;
	(*temp)[*j] = malloc(ft_strlen(daft[r]) + 1 * sizeof(char));
	ft_strlcpy((*temp)[*j], daft[r], ft_strlen(daft[r]) + 1);
	return (*temp);
}

int	check_list(t_mini	*list)
{
	t_mini	*ptr;

	ptr = list;
	while (list && list->next)
		list = list->next;
	if (!fix_cmp(list->data, "<") || !fix_cmp(list->data, ">")
		|| !fix_cmp(list->data, "|") || !fix_cmp(ptr->data, "|"))
	{
		printf("bash: syntax error near unexpected token %s\n", list->data);
		return (0);
	}
	return (1);
}

void	convert_space2(t_main_list **m_list)
{
	int (j) = 0;
	int (i) = -1;
	while ((*m_list)->tdm[++i])
	{
		j = -1;
		while ((*m_list)->tdm[i][++j])
		{
			if ((*m_list)->tdm[i][j] == '`')
				(*m_list)->tdm[i][j] = ' ';
		}
	}
	is_there_flag((*m_list));
}

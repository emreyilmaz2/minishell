/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataskin <ataskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:58:46 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/25 04:12:22 by ataskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quotes(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '\'' || str[0] == '\"')
	{
		if (str[len - 1] == '\'' || str[len - 1] == '\"')
			return (1);
	}
	return (0);
}

int	ft_check(char *str)
{
	int (i) = -1;
	int (counts) = 0;
	int (countd) = 0;
	while (str[++i])
	{
		if (str[i] == '<' && ((str[i + 1] == '<' && str[i + 2] == '<')
				|| str[i + 1] == '|'))
			return (0);
		else if (str[i] == '>' && ((str[i + 1] == '>' && str[i + 2] == '>')
				|| str[i + 1] == '|'))
			return (0);
		else if (str[i] == '|' && (str[i + 1] == '|' || str[i + 1] == '>'
				|| str[i + 1] == '<'))
			return (0);
		else if (str[i] == '\'')
			counts++;
		else if (str[i] == '\"')
			countd++;
	}
	if (!isEven(counts) || !isEven(countd))
		return (-1);
	return (1);
}

void	convert_space(char *str)
{
	int (j) = 0;
	int (i) = 0;
	int (flag) = 0;
	while (str[i])
	{
		if (str[i] == '"')
			flag++;
		if (str[i] == ' ' && isEven(flag))
			str[i] = '^';
		else if(str[i] == ' ' && !isEven(flag))
			str[i] = '`';
		i++;
	}
}

int	left_right(char *input, int *j, int flag)
{
	int (counter) = 0;
	if (flag == 0)
	{
		if (input[(*j) - 1] && input[(*j) - 1] > 32)
			counter++;
		if (input[(*j) + 1] && input[(*j) + 1] > 32)
			counter++;
		(*j)++;
	}
	else if (flag == 2)
	{
		if (input[(*j) - 2] && input[(*j) - 2] > 32)
			counter++;
		if (input[(*j) + 2] && input[(*j) + 2] > 32)
			counter++;
		(*j) += 2;
	}
	return (counter);
}

t_mini	*lexer(t_data *can)
{
	t_mini	*list;
	char	**string;
	int		i;

	convert_space(can->data);
	can->str = ft_split(can->data, '^');
	i = ft_size_array(can->str) + counter2(can->str);
	string = this_is_not_split(can->str, i, -1, -1);
	list = malloc(sizeof(t_mini));
	list = build_list(string, list);
	two_d_free(string);
	return (list);
}

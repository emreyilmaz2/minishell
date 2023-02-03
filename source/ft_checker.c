/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:38:53 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/30 23:55:30 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_input(char *str)
{
	int	j;

	j = ft_check(str);
	if (j == 0)
		write(1,
			"minishell: syntax error near unexpected token '< or > or |'\n",
			61);
	else if (j == -1)
		write(1, "minishell: missing quote\n", 25);
	else
		return (1);
	return (0);
}

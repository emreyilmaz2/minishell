/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:38:53 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/24 19:04:12 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checker(char *str)
{
	int	j;

	j = ft_check(str);
	if (j == 0)
		write(1, "bad operator\n", 13);
	else if (j == -1)
		write(1, "bad qutoes\n", 11);
	else
		return (1);
	return (0);
}

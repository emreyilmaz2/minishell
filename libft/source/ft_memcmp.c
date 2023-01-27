/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 02:45:42 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/04/07 15:33:02 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*string_s1;
	const unsigned char		*string_s2;
	size_t					i;

	i = 0;
	string_s1 = (const unsigned char *)s1;
	string_s2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (string_s1[i] != string_s2[i])
			return (string_s1[i] - string_s2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:54:37 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/04/07 15:49:54 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (index < n && (s1[index] || s2[index]))
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	char a[] = "punk";
	char b[] = "punkm";
	int result;
    int i;

    i = 5;
	result = strncmp(a, b, i);
    
    if (result == 0)
        printf("if we compare them %d times, they are equal\n %d", i,result);
    else
        printf("if we compare them %d times, the difference: %d", i,result);
}
*/
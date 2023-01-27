/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilmaz <emreyilmaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:23:06 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/04/07 03:12:51 by emreyilmaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size > 0)
	{
		while (index < (size - 1) && src[index])
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	while (src[index])
		index++;
	return (index);
}

/*
#include <stdio.h>
int	main ()
{
    char a[] = "Daft";
    char b[] = "Punk";
    int result;

    result = ft_strlcpy(a, b, 4);
    printf("%d", result);

    int i;

    i = 0;
    while(a[i])
    {
        printf("%c", a[i]);
        i++;
    }
    i = 0;
    while(b[i])
    {
        printf("%c", b[i]);
        i++;
    }
}
*/

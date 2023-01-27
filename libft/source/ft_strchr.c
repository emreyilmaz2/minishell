/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilmaz <emreyilmaz@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:22:43 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/04/07 03:12:56 by emreyilmaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
int	main()
{
	char a[] = "promo";
	
	printf("ft_:%s", ft_strchr(a, 'm'));
}
*/

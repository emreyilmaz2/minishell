/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:16:25 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/04/07 15:41:24 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t len)
{
	unsigned char	*emptr;
	unsigned char	nc;

	emptr = (unsigned char *)ptr;
	nc = (unsigned char)c;
	while (len > 0)
	{
		if (*emptr == nc)
			return (emptr);
		emptr++;
		len--;
	}
	return (NULL);
}

/*
int main()
{
	char oguz[] = "yalansa dogru de";
	
	printf("%p", ft_memchr(oguz, 'd', 16));
}
*/

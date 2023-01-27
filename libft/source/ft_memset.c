/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:21:35 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/04/07 15:38:25 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int letter, size_t n)
{
	char	*ptr;
	size_t	index;

	ptr = (char *)str;
	index = 0;
	while (index < n)
	{
		ptr[index] = letter;
		index++;
	}
	return (ptr);
}

/*
int main()

{
    char dizi[] = "blablabla";
    printf("%s", ft_memset(dizi, 'o', 6));
    return (0);
}
*/
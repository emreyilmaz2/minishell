/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:24:25 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/04/07 15:48:03 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*twin;
	size_t	i;

	twin = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!twin)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		twin[i] = str[i];
		i++;
	}
	twin[i] = '\0';
	return (twin);
}

/*
int main()
{
	    char x[] = "taytay";
		printf("%s", ft_strdup(x));
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:17:27 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/04/07 15:14:42 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	str = (char *)malloc (ft_strlen(s) + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
char upper(unsigned int i, char s)
{
  char x;
  x = s - 32;
  return (x);
}

int main() 
{
  char bilal[] = "bilal";
  printf("%s", ft_strmapi(bilal, upper));
  printf("%s", bilal);
  return (0);
}
*/
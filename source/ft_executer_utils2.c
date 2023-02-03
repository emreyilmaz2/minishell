/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executer_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 06:18:20 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 06:19:19 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_str_in_str2(const char *s, char *c)
{
	while (*s && *s != *c && *s + 1 != *c + 1)
	{
		if (*s == *c && *s + 1 == *c + 1)
			return (1);
		s++;
	}
	return (0);
}

int	ft_str_in_char(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return (1);
	return (0);
}

char	*ft_strtrim2(char const *s1, char set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	index;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && s1[start] == set)
		start++;
	while (end > start && s1[end - 1] == set)
		end--;
	str = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (start < end)
		str[index++] = s1[start++];
	str[index] = '\0';
	return (str);
}

int	ft_str_in_str(const char *s1, int start, const char *s2)
{
	int (i) = 0;
	int (len) = 0;
	while (s2[len])
		len++;
	while (s1[start] == s2[i] && s1[start] && s2[i] && i < len)
	{
		i++;
		start++;
		if (!s2[i])
			return (1);
	}
	return (0);
}

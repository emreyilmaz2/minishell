/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:44:21 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 06:13:52 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			cnt;
	unsigned int	diff;

	cnt = 0;
	diff = 0;
	while (!diff && (s1[cnt] != 0) && (s2[cnt] != 0))
	{
		diff = (unsigned char)s1[cnt] - (unsigned char)s2[cnt];
		cnt++;
	}
	if (!diff && (s1[cnt] == 0 || s2[cnt] == 0))
		diff = (unsigned char)s1[cnt] - (unsigned char)s2[cnt];
	return (diff);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	j;
	unsigned int	a;

	if (!s)
		return (NULL);
	arr = (char **) ft_calloc(str_in_array(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	a = -1;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while ((*s != c && (*s && ++j)))
				s++;
			arr[++a] = (char *) ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(arr[a], s - j, j + 1);
		}
	}
	arr[a + 1] = NULL;
	return (arr);
}

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int (im)[2] = {0, 0};
	size_t (n_len) = ft_strlen(needle);
	char *(hay) = (char *)haystack;
	if (n_len == 0 || haystack == needle)
		return (0);
	while (hay[im[0]] != '\0' && im[0] < len)
	{
		im[1] = 0;
		while (hay[im[0] + im[1]] != '\0' && needle[im[1]] != '\0'
			&& hay[im[0] + im[1]] == needle[im[1]] && im[0] + im[1] < len)
				im[1]++;
		if (hay[im[0] + im[1]] == needle[0])
			return (1);
		if (im[1] == n_len && hay[im[0] + im[1]] == ' ')
			return (0);
		else if (hay[im[0] + im[1]] == '\0')
		{
			printf("parse error near '\\n'\n");
			return (1);
		}
		im[0]++;
	}
	return (1);
}

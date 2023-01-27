/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:44:21 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/24 05:50:58 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "minishell.h"

int	twod_len(char **str)
{
	int (i) = 0;
	while (str[i])
		i++;
	return (i);
}
int	ft_size_array(char **array)
{
	int i;

	i = 0;
	while(array[i])
		i++;
	return(i);
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
 int ft_two_dim_len(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

void two_d_free(char **str)
{
	int (i) = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void three_d_free(char ***str)
{
	int	(i) = -1;
	int (j) = -1;
	while(str[++i])
	{
		j = -1;
		while(str[i][++j])
		{
			free(str[i][j]);
		}
		free(str[i]);
	}
	free(str);
}
int ft_str_in_str(const char *s1, int start, const char *s2)
{
	int (i) = 0;
	int len = 0;
	while(s2[len])
		len++;
	while(s1[start] == s2[i] && s1[start] && s2[i] && i < len)
	{
		i++;
		start++;
		if(!s2[i])
			return(1);
	}
	return (0);
}
int ft_findlen(const char *s, char c)
{
	int (i) = 0;

	while(s[i] && s[i] != c)
		i++;
	if(s[i] == c)
		return(i);
	return(0);
}
int	check_dquote(char *str)
{
	if (ft_strchr(str, 39))
	{
		if (ft_strchr(str, 34))
		{
			if (ft_findlen(str, 34) < ft_findlen(str, 39))
				return (1);
			return (0);
		}
		return (0);
	}
	else
		return (1);
}
int isEven(int n)
{
    // n^1 is n+1, then even, else odd
    if ((n ^ 1) == (n + 1))
        return 1;
    else
        return 0;
}

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
	// flag ile çift tırnak içineki boşlukları geçmesini sağladım. ama seg yiyor amk.
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
 			{
				s++;
			}
			arr[++a] = (char *) ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(arr[a], s - j, j + 1);
		}
	}
	arr[a + 1] = NULL;
	return (arr);
}

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*hay;

	i = 0;
	hay = (char *)haystack;
	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return (0);
	while (hay[i] != '\0' && i < len)
	{
		c = 0;
		while (hay[i + c] != '\0' && needle[c] != '\0'
			&& hay[i + c] == needle[c] && i + c < len)
				c++;
		if(hay[i+c] == needle[0])
			return(1);
		if (c == n_len && hay[i+c] == ' ')
			return (0);
		else if(hay[i+c] == '\0')
		{
			printf("parse error near '\\n'\n");
			return(1);
		}
		i++;
	}
	return (1);
}
static int	ft_checkset(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index++] == c)
			return (1);
	}
	return (0);
}

void	free_stack(t_mini *stack)
{
	t_mini	*tmp;
	t_mini	*delete;
	tmp = stack;
	while (tmp)
	{
		delete = tmp;
		tmp = tmp->next;
		free(delete->data);
		free(delete);
	}
}

int	fix_cmp(const char *s1,const char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (1);
	if (!s2)
		return (1);
	while (s1[i] && s2[i] && s2[i] == s1[i])
		i++;
	return (s1[i] - s2[i]);
}
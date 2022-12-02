#include "minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;	

	tot_size = size * count;
	dst = malloc(tot_size);
	if (!(dst))
		return (0);
	ft_memset(dst, 0, tot_size);
	return (dst);
}

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

int word_count(char *str, char c)
{
	int i = 0;
	int len = 1;
	while(str[i++] < 32);
	while(str[i] != '\0')
	{
		if(str[i] == c)
			len++;
		i++;
	}
	return (len);
}

unsigned int	str_in_array(const char *s, char delimiter)
{
	unsigned int	counter;

	counter = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			while (*s != delimiter && *s)
				s++;
			counter++;
		}
	}
	return (counter);
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
			while (*s != c && *s && ++j)
				s++;
			arr[++a] = (char *) ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(arr[a], s - j, j + 1);
		}
	}
	return (arr);
}
// void	split(t_data *can, char indicator)
// {
// 	int fakei;
// 	int k;
// 	int t = 0;
// 	int i = 0;
// 	int j = 0;
// 	//          12 emre okuma ogreniyor
// 	can->str = malloc(word_count(can->data," ")+1);
// 	while(can->data[i++]<32);
// 	fakei = i;
// 	while(can->data[i])
// 	{
// 		if(can->data[i] == indicator)
// 		{
// 			k = fakei;
// 			can->str[j] = malloc(i-k);
// 			while(k < i)
// 			{
// 				can->str[j][t++] = can->data[k++];
// 			}
// 			can->str[j][t] = '\0';
// 		}
// 	}
// }
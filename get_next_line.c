/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:22:09 by mobushi           #+#    #+#             */
/*   Updated: 2022/09/20 20:11:49 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	tmp = malloc(count * size);
	if (tmp == NULL)
		return (NULL);
	ft_memset (tmp, 0, size * count);
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (i + j + 1));
	if (tmp == NULL)
		return (NULL);
	while (k < i)
	{
		tmp[k] = ((char *)s1)[k];
		k++;
	}
	while (k < i + j)
	{
		tmp[k] = ((char *)s2)[k - i];
		k++;
	}
	tmp[k] = '\0';
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*tmp;
	unsigned char	c;

	tmp = (unsigned char *)buf;
	c = (unsigned char)ch;
	while (n > 0)
	{
		*tmp++ = c;
		n--;
	}
	return (buf);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
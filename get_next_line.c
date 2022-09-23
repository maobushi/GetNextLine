/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:22:09 by mobushi           #+#    #+#             */
/*   Updated: 2022/09/23 21:59:22 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *buf)
{
	size_t	i;
	size_t	j;
	char	*output;

	i = 0;
	j = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	output = ft_calloc(ft_strlen(buf) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buf[i] != '\0')
	{
		output[j] = buf[i];
		i++;
		j++;
	}
	free(buf);
	return (output);
}

char	*ft_free(char *original, char*add)
{
	char	*tmp;

	tmp = ft_strjoin(original, add);
	free(original);
	return (tmp);
}

char	*ft_read_file(int fd, char *buf)
{
	int		judge;
	char	*tmp;

	if (!buf)
		buf = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + (size_t)1, sizeof(char));
	judge = 1;
	while (judge > 0)
	{	
		judge = read(fd, tmp, BUFFER_SIZE);
		if (judge < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[judge] = '\0';
		buf = ft_free(buf, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buf);
}

char	*ft_storage(char *input)
{
	char	*output;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!input[i])
		return (NULL);
	while (input[i] != '\0' && input[i] != '\n')
		i++;
	output = ft_calloc(i + 2, sizeof(char));
	while (input[j] != '\0' && input[j] != '\n')
	{
		output[j] = input[j];
		j++;
	}
	output[j] = '\0';
	if (input[j] && input[j] == '\n')
		output[j++] = '\n';
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = ft_read_file (fd, buf);
	if (!buf)
		return (NULL);
	output = ft_storage (buf);
	buf = ft_next (buf);
	return (output);
}

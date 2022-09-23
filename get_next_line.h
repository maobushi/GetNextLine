/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:21:38 by mobushi           #+#    #+#             */
/*   Updated: 2022/09/23 22:03:49 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<fcntl.h>
# include<limits.h>
# include<stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_free(char *original, char*add);
void	*ft_memset(void *buf, int ch, size_t n);
char	*ft_next(char *buf);
char	*ft_read_file(int fd, char *buf);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_storage(char *input);
char	*get_next_line(int fd);

#endif
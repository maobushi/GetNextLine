/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:21:38 by mobushi           #+#    #+#             */
/*   Updated: 2022/09/20 20:11:54 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>
# include<limits.h>
# include<stdlib.h>

#define BUFFER_SIZE 2


char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *buf, int ch, size_t n);
char	*ft_strchr(const char *s, int c);

#endif
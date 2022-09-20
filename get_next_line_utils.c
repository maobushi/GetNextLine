/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:02:18 by mobushi           #+#    #+#             */
/*   Updated: 2022/09/20 21:49:41 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
	
char *ft_free(char * original, char*add)
{
	char *tmp;
	tmp = ft_strjoin(original,add);
	free(original);
	//printf("THISIS%s\n",tmp);
	return(tmp);
}

//open file and count words in bufsize, convert them into static char by using malloc
char *ft_read_file(int fd, char * buf)
{
	size_t i;
	int judge;

	i = 0;
	char *tmp;
	char *output;

	if (!buf)
		buf = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1,sizeof(char));
	

	judge = 1;
	while(judge > 0)//increment to eof
	{	
		
		judge = read(fd,tmp,BUFFER_SIZE);
		
		if(judge < 0)
			{
			free(tmp);
			return(NULL);
			}

		printf("%d\n",judge);
		printf("buf : %s\n",buf);
		printf("tmp : %s\n",tmp);
		buf = ft_free(buf,tmp);

		if(ft_strchr(buf,'\n'))
			break;
		
		i++;
	}
	return(buf);
}


char *get_next_line(int fd)
{
	static char *buf;

	buf = ft_read_file(fd,buf);
	return(buf);
}

int	main(void)
{
	char	*line;

	int		i;
	int		fd1;
	fd1 = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);


	
	return (0);
}


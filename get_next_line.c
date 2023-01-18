/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:03:55 by dde-sott          #+#    #+#             */
/*   Updated: 2023/01/18 19:51:34 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		ft_clean_buffer(buffer);
		return (NULL);
	}
	temp = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		temp = ft_strjoin(temp, buffer);
		if (ft_check_n(buffer))
			break ;
	}
	return (temp);
}

//apagar

/*#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>

int main()
{
	int fd = 0;
	char *line1;
	char *line2;
	
	fd = open("./test.txt", O_RDWR);
	line1 = get_next_line(fd);
	line2 = get_next_line(fd);
	printf("%s", line1);
	printf("%s", line2);
	close(fd);
}*/
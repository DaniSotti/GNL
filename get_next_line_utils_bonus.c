/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:02:39 by dde-sott          #+#    #+#             */
/*   Updated: 2023/02/02 00:13:47 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *temp, char *buffer)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = malloc(ft_strlen(temp) + ft_strlen(buffer) + 1);
	i = 0;
	j = 0;
	if (!newstr)
		return (NULL);
	while (temp && temp[i])
		newstr[j++] = temp[i++];
	free (temp);
	i = 0;
	while (buffer && buffer[i])
	{
		newstr[j++] = buffer[i];
		if (buffer[i++] == '\n')
			break ;
	}
	newstr[j] = '\0';
	return (newstr);
}

char	*ft_clean_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		buffer[j] = 0;
		i++;
	}
	return (NULL);
}

int	ft_is_nline(char *buffer)
{
	int	is_nline;
	int	i;
	int	j;

	i = 0;
	j = 0;
	is_nline = 0;
	while (buffer[i])
	{
		if (is_nline)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			is_nline = 1;
		buffer[i++] = 0;
	}
	return (is_nline);
}

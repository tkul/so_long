/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:56:02 by tkul              #+#    #+#             */
/*   Updated: 2024/04/28 01:59:06 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_putremain(char *putline)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (putline[i] != '\0' && putline[i] != '\n')
		i++;
	if (!putline[i])
	{
		free(putline);
		return (NULL);
	}
	str = (char *)ft_calloc_gnl(sizeof(char), (ft_strlen(putline) - i));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (putline[i + j] != '\0')
	{
		str[j] = putline[j + i];
		j++;
	}
	free(putline);
	return (str);
}

char	*get_main_line(char *putline)
{
	int		i;
	char	*str;

	i = 0;
	if (!putline[i])
		return (NULL);
	while (putline[i] != '\0' && putline[i] != '\n')
		i++;
	str = (char *)ft_calloc_gnl(sizeof(char), i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (putline[i] != '\0' && putline[i] != '\n')
	{
		str[i] = putline[i];
		i++;
	}
	if (putline[i] == '\n')
	{
		str[i] = putline[i];
		i++;
	}
	return (str);
}

char	*get_read(int fd, char *putline)
{
	char	*buff;
	int		reader;

	buff = (char *)ft_calloc_gnl(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	reader = 1;
	while (!ft_strchr_gnl(putline, '\n') && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			free(putline);
			return (NULL);
		}
		buff[reader] = '\0';
		putline = ft_strjoin_gnl(putline, buff);
	}
	free(buff);
	return (putline);
}

char	*get_next_line(int fd)
{
	char		*mainline;
	static char	*putline[10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	putline[fd] = get_read(fd, putline[fd]);
	if (!putline[fd])
		return (NULL);
	mainline = get_main_line(putline[fd]);
	putline[fd] = get_putremain(putline[fd]);
	return (mainline);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:10:03 by tlorne            #+#    #+#             */
/*   Updated: 2023/02/23 18:54:14 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_clean_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*newbuff;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	newbuff = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!newbuff)
		return (NULL);
	i++;
	while (buffer[i])
		newbuff[j++] = buffer[i++];
	free(buffer);
	return (newbuff);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (buffer[0] == 0)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_join_and_free(char *buffer, char *temp)
{
	char	*temp2;

	temp2 = ft_strjoin(buffer, temp);
	free(buffer);
	return (temp2);
}

char	*ad_read_uend(int fd, char *buffer)
{
	int		res;
	char	*temp;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	res = 1;
	while (!(ft_strchr(buffer, '\n')) && res > 0)
	{
		res = read(fd, temp, BUFFER_SIZE);
		if (res == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[res] = '\0';
		buffer = ft_join_and_free(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(BUFFER_SIZE, sizeof(char));
	buffer[fd] = ad_read_uend(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_clean_buffer(buffer[fd]);
	return (line);
}

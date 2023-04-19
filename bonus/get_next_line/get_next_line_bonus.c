/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:14:04 by pcocci            #+#    #+#             */
/*   Updated: 2022/11/25 11:24:15 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*new_txt(char *txt)
{
	int		i;
	int		j;
	char	*new_txt;

	i = 0;
	while (txt[i] && txt[i] != '\n')
		i++;
	if (!txt[i])
	{
		free(txt);
		return (NULL);
	}
	new_txt = (char *)malloc((ft_strlen(txt) - i + 1) * sizeof(*new_txt));
	if (!new_txt)
		return (NULL);
	i++;
	j = 0;
	while (txt[i])
		new_txt[j++] = txt[i++];
	new_txt[j] = '\0';
	free(txt);
	return (new_txt);
}

char	*get_txt(int fd, char *buffer, char *txt)
{
	int		i;

	i = 1;
	while (!ft_strchr(txt, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		txt = ft_strjoin(txt, buffer);
	}
	free(buffer);
	return (txt);
}

char	*get_line(char *txt)
{
	int		j;
	char	*line;

	j = 0;
	if (txt[j] == '\0')
		return (NULL);
	while (txt[j] != '\n' && txt[j])
		j++;
	line = malloc((j + 2) * sizeof(*line));
	j = 0;
	if (!line)
		return (NULL);
	while (txt[j] != '\n' && txt[j])
	{
		line[j] = txt[j];
		j++;
	}
	if (txt[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*txt[FOPEN_MAX];
	char			*line;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE +1) * (sizeof(*buffer)));
	if (!buffer)
		return (NULL);
	txt[fd] = get_txt(fd, buffer, txt[fd]);
	if (!txt[fd])
		return (NULL);
	line = get_line(txt[fd]);
	txt[fd] = new_txt(txt[fd]);
	return (line);
}

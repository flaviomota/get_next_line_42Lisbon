/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:17:59 by fmota             #+#    #+#             */
/*   Updated: 2021/05/14 12:30:53 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)s - 1);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_blankline(char *save, char **line, int x)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(save))
	{
		*line = ft_substr(save, 0, i);
		tmp = ft_substr(save, i + 1, ft_strlen(save));
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else if (x == 0)
	{
		*line = save;
		save = NULL;
	}
	return (save);
}

char	*ft_tosave(char *buffer, char *save)
{
	char	*tmp;

	if (save)
	{
		tmp = ft_strjoin(save, buffer);
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else
		save = ft_strdup(buffer);
	return (save);
}

int	ft_aux(int x, char *save)
{
	if (x <= 0 && !save)
		return (x);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[4096];
	char		buffer[BUFFER_SIZE + 1];
	int			x;

	if (!line || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	x = 1;
	while (x)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x == -1)
			return (-1);
		buffer[x] = '\0';
		save[fd] = ft_tosave(buffer, save[fd]);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (x <= 0 && !save[fd])
	{
		*line = ft_strdup("");
		return (x);
	}
	save[fd] = ft_blankline(save[fd], line, x);
	return (ft_aux(x, save[fd]));
}

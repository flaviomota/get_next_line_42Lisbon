/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:37:19 by fmota             #+#    #+#             */
/*   Updated: 2021/05/14 12:09:26 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (ft_strlen(s) > start)
	{
		while (s[start + index] && index < len)
		{
			str[index] = s[start + index];
			index++;
		}
	}
	str[index] = '\0';
	return (str);
}

static char	*ft_join(char const *s1, char const *s2, char *c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s1[x])
	{
		c[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		c[x + y] = s2[y];
		y++;
	}
	c[x + y] = '\0';
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * len + 1);
	if (!join)
		return (NULL);
	join = ft_join(s1, s2, join);
	return (join);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	copy = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

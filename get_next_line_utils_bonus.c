/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarvaez <pnarvaez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:39:44 by pnarvaez          #+#    #+#             */
/*   Updated: 2026/06/23 13:01:29 by pnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!copy)
		return (NULL);
	while (*src)
		copy[i++] = *src++;
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	char	*copy;

	copy = (char *) s;
	while (*copy)
	{
		if (*copy == (unsigned char) c)
			return (copy);
		copy++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	s = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (*s1)
		s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = '\0';
	return (s);
}

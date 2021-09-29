/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:04:02 by gabriel           #+#    #+#             */
/*   Updated: 2021/09/22 14:38:09 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlengnl(char *str)
{
	size_t	s;

	s = 0;
	if (!str)
		return (0);
	while (str[s])
		s++;
	return (s);
}

char	*ft_strchrgnl(char *s, int c)
{
	int	find;

	find = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlengnl(s)]);
	while (s[find])
	{
		if (s[find] == (char) c)
			return ((char *)&s[find]);
		find ++;
	}
	return (0);
}

char	*ft_strjoingnl(char *left_str, char *buffer)
{
	char			*new_str;
	size_t			s;
	size_t			n;
	int				lenstr;

	lenstr = ft_strlengnl(left_str);
	s = 0;
	n = 0;
	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	new_str = (char *) malloc (sizeof(char) * (lenstr + ft_strlengnl(buffer)) + 1);
	if (new_str == NULL)
		return (NULL);
	while (left_str[n] != '\0')
		new_str[n++] = left_str[s++];
	s = 0;
	while (buffer[s])
		new_str[n++] = buffer[s++];
	new_str[n] = '\0';
	free(left_str);
	return (new_str);
}

char	*ft_line(char *left_str)
{
	int			i;
	char		*str;

	i = 0;
	if (!left_str)
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *) malloc (sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_newleft(char *left_str)
{
	int			s;
	int			i;
	char		*str;

	i = 0;
	s = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (left_str[i] == '\0')
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlengnl(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (left_str[i])
		str[s++] = left_str[i++];
	str[s] = '\0';
	free(left_str);
	return (str);
}

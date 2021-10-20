/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:05:00 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/12 19:20:35 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s, char *save_str)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	save_str = malloc (sizeof(char *) * ft_strlen(s) + 1);
	if (save_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		save_str[i] = s[i];
		i++;
	}
	save_str[i] = '\0';
	return (save_str);
}

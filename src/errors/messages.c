/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:52:53 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/05 14:53:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *s)
{
	printf("\033[1;31mError: %s\n\033[0m", s);
	return (0);
}

void	*null_error(char *s)
{
	printf("\033[1;31mError: %s\n\033[0m", s);
	return (0);
}
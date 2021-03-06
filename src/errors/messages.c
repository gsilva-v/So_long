/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:52:53 by gabriel           #+#    #+#             */
/*   Updated: 2021/11/04 15:13:21 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *s)
{
	printf("\033[1;31mError: %s\n\033[0m", s);
	exit (0);
}

void	*null_error(char *s)
{
	printf("\033[1;31mError: %s\n\033[0m", s);
	exit (0);
}

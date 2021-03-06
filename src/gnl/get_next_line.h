/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:04:09 by gabriel           #+#    #+#             */
/*   Updated: 2021/10/02 08:20:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../../so_long.h"

char	*ft_strjoingnl(char *s1, char *s2);
char	*ft_strchrgnl(char *s, int c);
size_t	ft_strlengnl(char *str);
char	*ft_line(char *left_str);
char	*ft_newleft(char *left_str);
char	*get_next_line(int fd);
char	*ft_readleftstr(int fd, char *left_str);
#endif

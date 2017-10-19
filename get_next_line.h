/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:40:51 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/18 22:44:24 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE	100
# endif

typedef struct	s_data
{
	int			line_len;
	char		buff[BUFF_SIZE + 1];
}				t_data;

int	get_next_line(const int fd, char **line);

#endif

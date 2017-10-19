/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:28 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/18 23:40:23 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include "get_next_line.h"

/*
** shift_chars_left assumes shift_by < BUFF_SIZE
*/

static void	shift_chars_left(t_data *data, int shift_by)
{
	int i;

	i = 0;
	while (data->buff[i] && data->buff[i + shift_by])
	{
		data->buff[i] = data->buff[i + shift_by];
		i++;
	}
	ft_bzero(data->buff + i, BUFF_SIZE - i);
}

static void	buff_to_line(char **line, t_data *data, int copy_len)
{
	int shift_by;

	*line = ft_realloc(*line, data->line_len + 1);
	ft_strncat(*line, data->buff, copy_len);
	shift_by = (copy_len < BUFF_SIZE) ? copy_len + 1 : 0;
	shift_chars_left(data, shift_by);
}

static int	prelim_checks(char **line, t_data *data)
{
	char	*char_pos;

	char_pos = ft_strchr(data->buff, '\n');
	if (char_pos)
		data->line_len = char_pos - data->buff;
	else
		data->line_len = ft_strlen(data->buff);
	if (*line)
		ft_strclr(*line);
	buff_to_line(line, data, data->line_len);
	return ((char_pos != NULL));
}

static int	run_copy(char **line, t_data *data, int rv)
{
	char	*char_pos;
	int		copy_len;

	char_pos = ft_strchr(data->buff, '\n');
	copy_len = (char_pos) ? (char_pos - data->buff) : rv;
	data->line_len += copy_len;
	buff_to_line(line, data, copy_len);
	return ((char_pos != NULL));
}

int			get_next_line(const int fd, char **line)
{
	static t_data	data;
	int				rv;

	if (!(line))
		return (-1);
	if (prelim_checks(line, &data))
		return (1);
	if (((rv = read(fd, data.buff, BUFF_SIZE)) == 0 && ft_strlen(*line) == 0)
		|| rv == -1)
		return (rv);
	if (rv == 0 && ft_strlen(*line) > 0)
		return (1);
	while (rv)
	{
		if ((run_copy(line, &data, rv)) || rv == 0)
			return (1);
		if ((rv = read(fd, data.buff, BUFF_SIZE)) == -1)
			return (-1);
		if (rv == 0)
			return (1);
	}
	return (-1);
}

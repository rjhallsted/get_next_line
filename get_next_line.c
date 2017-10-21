/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:28 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/21 15:32:51 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Current things to change:
** 1) add support for multiple file descriptors
** 2) rename the static data functions to something more specific, and rename
** ** t_data as well. It's too general.
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "get_next_line.h"

#include <stdio.h>

static int		run_copy(char **line, t_data *data, int rv)
{
	char	*char_pos;
	int		copy_len;
	int		i;

	char_pos = ft_strchr(data->buff, '\n');
	copy_len = (char_pos) ? (char_pos - data->buff) : rv;
	data->line_len += copy_len;
	*line = ft_memrealloc(*line, data->line_len + 1);
	ft_strncat(*line, data->buff, copy_len);
	i = 0;
	copy_len++;
	while (data->buff[i] && data->buff[i + copy_len])
	{
		data->buff[i] = data->buff[i + copy_len];
		i++;
	}
	ft_bzero(data->buff + i, BUFF_SIZE - i);
	return ((char_pos != NULL));
}

static t_data	*new_data_item(int fd)
{
	t_data	*new;

	if (!(new = ft_memalloc(sizeof(t_data))))
		return (NULL);
	new->fd = fd;
	new->line_len = 0;
	ft_bzero(new->buff, BUFF_SIZE + 1);
	new->next = NULL;
	return (new);
}

static t_data	*find_data(t_data **first, int fd)
{
	t_data	*item;

	if (!first)
		return (NULL);
	item = NULL;
	if (!(*first))
	{
		*first = new_data_item(fd);
		return (*first);
	}
	item = *first;
	if (item->fd == fd)	
		return (item);
	while (item->next)
	{
		if (item->next->fd == fd)
			return (item->next);
		item = item->next;
	}
	item = *first;
	*first = new_data_item(fd);
	(*first)->next = item;
	return (item->next);
}

static void		free_data(t_data **first, t_data *data)
{
	t_data *tmp;
	t_data *item;

	if (!data || !first)
		return;
	if (*first == data)
	{
		tmp = data->next;
		free(data);
		*first = tmp;
	}
	else
	{
		item = *first;
		while (item->next != data)
			item = item->next;
		tmp = data->next;
		free(data);
		item->next = tmp;
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_data	*first;
	t_data			*data;
	int				rv;

	if (!(line) || fd < 0)
		return (-1);
	*line = NULL;
	if (!(data = find_data(&first, fd)))
		return (-1);
	printf("using fd %d\n", fd);
	if (ft_strlen(data->buff) > 0
		&& run_copy(line, data, ft_strlen(data->buff)))
		return (1);
	if ((rv = read(fd, data->buff, BUFF_SIZE)) == -1
		|| (rv == 0 && *line == NULL))
	{
		free_data(&first, data);
		return (rv);
	}
	if (rv == 0 && *line != NULL)
		return (1);
	while (rv)
	{
		printf("in loop\n");
		if (run_copy(line, data, rv))
			return (1);
		printf("buff: %s\n", data->buff);
		if ((rv = read(fd, data->buff, BUFF_SIZE)) == -1)
		{
			free_data(&first, data);
			return (-1);
		}
		if (rv == 0)
			return (1);
	}
	return (0);
}

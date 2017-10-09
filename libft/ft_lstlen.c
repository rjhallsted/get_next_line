/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 00:18:15 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/03 11:00:50 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_lstlen(t_list *item)
{
	int i;

	i = 0;
	while (item)
	{
		i++;
		item = item->next;
	}
	return (i);
}

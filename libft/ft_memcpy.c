/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:42:35 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/26 14:02:19 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Currently contains a bug. If the size is bigger than difference between the
** location of source and the end of usable memory, the program will segfault
** when it hits that point.
*/

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_str;
	const char	*src_str;
	size_t		i;

	dst_str = dst;
	src_str = src;
	i = 0;
	while (i < n)
	{
		dst_str[i] = src_str[i];
		i++;
	}
	return (dst);
}

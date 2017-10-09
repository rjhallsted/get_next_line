/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:47:11 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/21 10:37:42 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
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
		if (src_str[i] == c)
			return ((void *)(dst + i + 1));
		else
			i++;
	}
	return (NULL);
}

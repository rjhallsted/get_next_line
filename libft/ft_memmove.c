/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:55:02 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/21 11:25:04 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	void *save;

	save = dst;
	if (dst > src && dst - src < (long)len)
	{
		while (len > 0)
		{
			*(char *)(dst + len - 1) = *(char *)(src + len - 1);
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (save);
}

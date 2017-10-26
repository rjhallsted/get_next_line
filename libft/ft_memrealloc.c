/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 11:48:07 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/26 12:10:43 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memrealloc(void *src, size_t size)
{
	void *new;

	if (!src)
		return (ft_memalloc(size));
	if (!size)
		return (NULL);
	if (!(new = ft_memalloc(size)))
		return (NULL);
	ft_memmove(new, (const void*)src, size);
	free(src);
	return (new);
}

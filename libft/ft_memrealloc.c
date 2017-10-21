/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 11:47:09 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/21 11:47:11 by rhallste         ###   ########.fr       */
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
	ft_memcpy(new, (const void*)src, size);
	free(src);
	return (new);
}

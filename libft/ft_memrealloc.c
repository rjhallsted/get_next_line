/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 11:48:07 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/26 14:42:00 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#include <stdio.h>

void	*ft_memrealloc(void *src, size_t new_size, size_t old_size)
{
	void *new;

	if (!new_size)
		return (NULL);
	if (!src)
		return (ft_memalloc(new_size));
	if (!(new = ft_memalloc(new_size)))
		return (NULL);
//	printf("old: %p\n", src);
//	printf("new: %p\n", new);
	ft_memmove(new, (const void*)src, old_size);
	free(src);
	return (new);
}

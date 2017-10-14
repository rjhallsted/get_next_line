/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:22:06 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/13 18:29:28 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#include <stdio.h>

void	*ft_realloc(void *src, size_t size)
{
	void *new;

	if (!src)
		return (ft_memalloc(size));
	if (!size)
		return (NULL);
	if (!(new = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(new, src, size);
	free(src);
	return (new);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 10:47:04 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/22 19:41:19 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	numlen(unsigned int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*new;
	size_t	len;
	size_t	start;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = (n < 0) ? numlen(n * -1) + 1 : numlen(n);
	if (!(new = ft_strnew(len)))
		return (NULL);
	start = (n < 0);
	if (n < 0)
	{
		n *= -1;
		new[0] = '-';
	}
	while (len > start)
	{
		new[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (new);
}

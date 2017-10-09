/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 09:47:48 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/23 22:57:35 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char			*new;
	char			*start;
	unsigned int	len;

	if (s)
	{
		while (isspace(*s))
			s++;
		start = (char *)s;
		len = ft_strlen(s);
		if (len == 0)
			return (ft_strdup(""));
		len--;
		while (isspace(s[len]))
			len--;
		if (!(new = ft_strsub(start, 0, len + 1)))
			return (NULL);
		return (new);
	}
	return (NULL);
}

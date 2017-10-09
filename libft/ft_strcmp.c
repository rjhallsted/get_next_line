/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:42:17 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/25 13:14:52 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t len;

	len = (size_t)ft_max(ft_strlen(s1), ft_strlen(s2));
	return (ft_strncmp(s1, s2, len));
}

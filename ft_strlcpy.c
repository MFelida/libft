/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:19:39 by mfelida           #+#    #+#             */
/*   Updated: 2023/10/20 12:59:10 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	res;

	res = (ft_strlen(src));
	if (!size)
		return (res);
	i = 1;
	while (*src && size > 0 && i < size)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = 0;
	return (res);
}

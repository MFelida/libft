/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:19:39 by mfelida           #+#    #+#             */
/*   Updated: 2023/10/20 12:54:18 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	v;

	p = (unsigned char *) s;
	v = (unsigned char) c;
	while (n-- > 0)
	{
		if (*p == v)
			return ((void *) p);
		p++;
	}
	return (NULL);
}

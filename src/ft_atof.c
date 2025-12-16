/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifelida <mifelida@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:52:00 by mifelida          #+#    #+#             */
/*   Updated: 2025/12/16 16:00:15 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>

static size_t	_count_digits(const char *s)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

float	ft_atof(const char *s)
{
	float		res;
	const char	*dot;
	size_t		digits;

	res = ft_atoi(s);
	dot = ft_strchr(s, '.');
	if (!dot || !*++dot)
		return (res);
	digits = _count_digits(dot);
	if (!digits)
		return (res);
	res += ft_atoi(dot) / (digits * 10.0f);
	return (res);
}

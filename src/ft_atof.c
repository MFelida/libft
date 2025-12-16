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

static size_t _sign(const char *s)
{
	int ret;
	
	ret = 1;
	while (*s == '-' || *s == '+')
		if (*s++ == '-')
			ret *= -1;
	return (ret);
}

static float	_ft_pow(const int b, const unsigned int e)
{
	if (e == 0)
		return (1);
	return (b * _ft_pow(b, e - 1));
}

float	ft_atof(const char *s)
{
	float		res;
	int			sign;
	size_t		digits;

	sign = _sign(s);
	res = ft_atoi(s);
	s = ft_strchr(s, '.');
	if (!s || !*++s)
		return (res);
	digits = _count_digits(s);
	if (!digits)
		return (res);
	res += sign * ft_atoi(s) / _ft_pow(10, digits);
	return (res);
}

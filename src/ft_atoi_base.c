/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:17:11 by mfelida           #+#    #+#             */
/*   Updated: 2024/06/16 17:16:22 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	_valid_radix(const char *s)
{
	if (ft_strlen(s) < 2)
		return (0);
	while (*s && *(s+1))
	{
		if (ft_strchr(s+1, *s) || ft_strchr("+-", *s))
			return (0);
		++s;
	}
	return (1);
}

int	ft_atoi_base(const char *s, const char *base)
{
	int	res;
	int	is_neg;

	res = 0;
	is_neg = 0;
	if (!_valid_radix(base))
		return (0);
	while (*s && ft_isspace(*s))
		++s;
	while (*s && ft_strchr("+-", *s))
		if (*s++ == '-')
			is_neg = !is_neg;
	while (*s && ft_strchr(base, *s))
	{
		res *= ft_strlen(base);
		res += (int)(ft_strchr(base, *s) - base);
		++s;
	}
	if (is_neg)
		res *= -1;
	return (res);
}

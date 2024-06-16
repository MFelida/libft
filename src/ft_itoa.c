/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:04:06 by mfelida           #+#    #+#             */
/*   Updated: 2023/10/22 13:38:34 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static void		_ft_sputnbr(char *dest, int n);
static size_t	_n_digits(int n);

char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	if (n < 0)
		len = _n_digits(n) + 2;
	else
		len = _n_digits(n) + 1;
	res = malloc(len * sizeof (char));
	if (res == NULL)
		return (NULL);
	_ft_sputnbr(res, n);
	return (res);
}

static void	_ft_sputnbr_inner(char **const dest, long int n)
{
	if (n < 0)
	{
		*((*dest)++) = '-';
		n *= -1;
	}
	if (n / 10)
	{
		_ft_sputnbr_inner(dest, n / 10);
	}
	*((*dest)++) = (n % 10) | 0x30;
}

static void	_ft_sputnbr(char *dest, int n)
{
	_ft_sputnbr_inner(&dest, n);
	*dest = '\0';
}

static size_t	_n_digits(int n)
{
	size_t	res;

	res = 1;
	while (n / 10)
	{
		n /= 10;
		res++;
	}
	return (res);
}

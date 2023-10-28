/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:19:39 by mfelida           #+#    #+#             */
/*   Updated: 2023/10/27 17:46:23 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	ssize_t		res;

	nbr = n;
	res = 0;
	if (nbr < 0)
	{
		res += ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr / 10)
		res += ft_putnbr_fd(nbr / 10, fd);
	res += ft_putchar_fd((nbr % 10) + '0', fd);
	return (res);
}

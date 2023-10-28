/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:46:48 by mfelida           #+#    #+#             */
/*   Updated: 2023/10/28 15:37:08 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putuint_fd(unsigned int n, int fd)
{
	ssize_t		res;

	res = 0;
	if (n / 10)
		res += ft_putnbr_fd(n / 10, fd);
	res += ft_putchar_fd((n % 10) + '0', fd);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:49:03 by mfelida           #+#    #+#             */
/*   Updated: 2023/10/28 15:33:52 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_puthex_fd(unsigned long n, char *map, int fd)
{
	ssize_t			res;
	unsigned int	i;
	char			c;

	res = 0;
	i = 0;
	while (i < (2 * sizeof (unsigned long))
		&& !((((unsigned long) n) >> ((15 - i) * 4)) & 0x0F))
		i++;
	while (i < (2 * sizeof (void *)))
	{
		c = map[(((unsigned long) n) >> ((15 - i) * 4)) & 0x0F];
		res += ft_putchar_fd(c, fd);
		i++;
	}
	return (res);
}

ssize_t	ft_puthexu_fd(unsigned int n, int fd)
{
	if (!n)
		return (write(fd, "0", 1));
	return (ft_puthex_fd(n, "0123456789ABCDEF", fd));
}

ssize_t	ft_puthexl_fd(unsigned int n, int fd)
{
	if (!n)
		return (write(fd, "0", 1));
	return (ft_puthex_fd(n, "0123456789abcdef", fd));
}

ssize_t	ft_putpntr_fd(void *p, int fd)
{
	ssize_t	res;

	if (!p)
		return (ft_putstr_fd("(nil)", STDOUT_FILENO));
	res = 0;
	res += ft_putstr_fd("0x", STDOUT_FILENO);
	res += ft_puthex_fd((unsigned long)p, "0123456789abcdef", fd);
	return (res);
}

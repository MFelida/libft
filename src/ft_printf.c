/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:54:32 by mfelida           #+#    #+#             */
/*   Updated: 2024/02/05 13:26:32 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
#include <stdarg.h>

static int	ft_vfprintf(int fd, const char **c, va_list arg);

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	size_t	i;
	int		res;

	va_start(args, fmt);
	res = 0;
	while (*fmt)
	{
		i = 0;
		while (fmt[i] && fmt[i] != '%')
			i++;
		res += write(STDOUT_FILENO, fmt, i);
		fmt += i;
		if (*fmt == '%')
		{
			fmt++;
			res += ft_vfprintf(STDOUT_FILENO, &fmt, args);
		}
	}
	va_end(args);
	return (res);
}

int	ft_fprintf(int fd, const char *fmt, ...)
{
	va_list	args;
	size_t	i;
	int		res;

	va_start(args, fmt);
	res = 0;
	while (*fmt)
	{
		i = 0;
		while (fmt[i] && fmt[i] != '%')
			i++;
		res += write(fd, fmt, i);
		fmt += i;
		if (*fmt == '%')
		{
			fmt++;
			res += ft_vfprintf(fd, &fmt, args);
		}
	}
	va_end(args);
	return (res);
}

static int	ft_vfprintf(int fd, const char **c, va_list arg)
{
	int	res;

	if (**c == 'c')
		res = ft_putchar_fd((char) va_arg(arg, int), fd);
	else if (**c == 's')
		res = ft_putstr_fd(va_arg(arg, char *), fd);
	else if (**c == 'p')
		res = ft_putpntr_fd(va_arg(arg, void *), fd);
	else if (**c == 'd' || **c == 'i')
		res = ft_putnbr_fd(va_arg(arg, int), fd);
	else if (**c == 'u')
		res = ft_putuint_fd(va_arg(arg, unsigned int), fd);
	else if (**c == 'x')
		res = ft_puthexl_fd(va_arg(arg, unsigned int), fd);
	else if (**c == 'X')
		res = ft_puthexu_fd(va_arg(arg, unsigned int), fd);
	else if (**c == '%')
		res = ft_putchar_fd('%', fd);
	else
		return (ft_putchar_fd('%', fd));
	(*c)++;
	return (res);
}

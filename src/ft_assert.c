/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifelida <mifelida@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:37:21 by mifelida          #+#    #+#             */
/*   Updated: 2025/12/03 15:49:24 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <unistd.h>

void	_ft_assert_debug(const int check, ...)
{
	va_list		v;
	const char	*msg;

	if (check)
		return ;
	ft_putstr_fd("Assertion Error", STDERR_FILENO);
	va_start(v, check);
	msg = va_arg(v, char *);
	while (msg)
	{
		ft_fprintf(STDERR_FILENO, ": %s", msg);
		msg = va_arg(v, char *);
	}
	va_end(v);
	ft_putchar_fd('\n', STDERR_FILENO);
	ft_exit(1);
}

void	_ft_assert_release(const int check, ...)
{
	(void) check;
}

#ifndef DEBUG

void	ft_assert(const int check, ...)
		__attribute__((sentinel, alias("_ft_assert_release")));
#else

void	ft_assert(const int check, ...)
		__attribute__((sentinel, alias("_ft_assert_debug")));
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifelida <mifelida@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:36:07 by mifelida          #+#    #+#             */
/*   Updated: 2025/08/28 16:22:37 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "libft.h"

static	int	_print_context(size_t n_context_str, va_list args)
{
	int		printf_ret;
	int		res;

	printf_ret = 0;
	res = 0;
	while (n_context_str > 0 && printf_ret >= 0)
	{
		printf_ret = ft_fprintf(STDERR_FILENO, "%s: ",
				va_arg(args, const char *));
		res += printf_ret;
		n_context_str--;
	}
	if (printf_ret < 0)
		return (printf_ret);
	return (res);
}

int	ft_print_err(const char *error_msg, size_t n_context_str, ...)
{
	va_list	args;
	int		printf_ret;
	int		res;

	res = 0;
	printf_ret = 0;
	if (n_context_str > 0)
	{
		va_start(args, n_context_str);
		printf_ret = _print_context(n_context_str, args);
		va_end(args);
	}
	if (printf_ret < 0)
		return (printf_ret);
	res += printf_ret;
	printf_ret = ft_fprintf(STDERR_FILENO, "%s\n", error_msg);
	if (printf_ret < 0)
		return (printf_ret);
	return (res + printf_ret);
}

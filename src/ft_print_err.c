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
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

static	int	_print_context(char **dest, size_t n_context_str, va_list args)
{
	int			printf_ret;
	int			len;
	int			new_len;
	const char	*va_str;

	printf_ret = 0;
	len = 0;
	while (n_context_str > 0 && printf_ret >= 0)
	{
		va_str = va_arg(args, const char *);
		new_len = ft_strlen(*dest) + ft_strlen(va_str) + 2;
		*dest = ft_realloc(*dest, new_len + 1, len + 1);
		if (!*dest)
			return (-1);
		len = new_len;
		ft_strlcat(*dest, va_str, len + 1);
		ft_strlcat(*dest, ": ", len + 1);
		n_context_str--;
	}
	return (len);
}

int	ft_print_err(const char *error_msg, size_t n_context_str, ...)
{
	va_list	args;
	int		res;
	char	*buff;

	if (!error_msg)
		return (-1);
	buff = ft_strdup("");
	if (!buff)
		return (-1);
	res = 0;
	if (n_context_str > 0)
	{
		va_start(args, n_context_str);
		res = _print_context(&buff, n_context_str, args);
		va_end(args);
	}
	if (res < 0)
		return (res);
	buff = ft_realloc(buff, res + ft_strlen(error_msg) + 1, res + 1);
	if (!buff)
		return (-1);
	ft_strlcat(buff, error_msg, res + ft_strlen(error_msg) + 1);
	res = ft_putendl_fd(buff, STDERR_FILENO);
	free(buff);
	return (res);
}

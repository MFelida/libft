/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 21:12:35 by mfelida           #+#    #+#             */
/*   Updated: 2024/10/03 22:05:32 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

char	*ft_ftoa(float f, size_t n_after_period)
{
	char	*res;
	char	*temp;
	size_t	len;

	if (n_after_period == 0)
		return (ft_itoa(roundf(f)));
	temp = ft_itoa(f);
	if (!temp)
		return (NULL);
	len = ft_strlen(temp);
	res = malloc((len + 2 + n_after_period) * sizeof(char));
	if (!res)
	{
		free(temp);
		return (NULL);
	}
	ft_strlcpy(res, temp, len + 1);
	free(temp);
	res[len] = '.';
	f = fabsf(f);
	f = (f - floorf(f)) * powf(10, n_after_period);
	temp = ft_itoa(roundf(f));
	ft_strlcpy(res + len + 1, temp, n_after_period + 1);
	free(temp);
	return (res);
}

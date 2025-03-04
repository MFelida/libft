/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 21:12:35 by mfelida           #+#    #+#             */
/*   Updated: 2025/03/04 11:43:32 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define BUFFER_SIZE 256

char	*ft_ftoa(float f, size_t n_after_period)
{
	char	res[BUFFER_SIZE];
	char	*temp;

	if (n_after_period == 0)
		return (ft_itoa(roundf(f)));
	temp = ft_itoa(f);
	if (!temp)
		return (NULL);
	res[0] = '\0';
	if (f < 0 && f > -1)
		ft_strlcpy(res, "-", BUFFER_SIZE);
	ft_strlcat(res, temp, BUFFER_SIZE);
	free(temp);
	ft_strlcat(res, ".", BUFFER_SIZE);
	f = fabsf(f);
	f = (f - floorf(f)) * powf(10, n_after_period);
	temp = ft_itoa(roundf(f));
	if (!temp)
		return (NULL);
	ft_strlcat(res, temp, BUFFER_SIZE);
	free(temp);
	return (ft_strdup(res));
}

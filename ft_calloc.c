/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:19:39 by mfelida           #+#    #+#             */
/*   Updated: 2023/10/20 13:08:31 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}

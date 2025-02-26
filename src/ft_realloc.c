/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifelida <mifelida@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:13:01 by mifelida          #+#    #+#             */
/*   Updated: 2025/02/26 14:20:03 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		return (ptr);
	ft_memcpy(res, ptr, size);
	free(ptr);
	return (res);
}

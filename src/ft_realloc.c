/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifelida <mifelida@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:13:01 by mifelida          #+#    #+#             */
/*   Updated: 2025/03/05 14:27:21 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
	void	*res;

	res = malloc(new_size);
	if (!res)
		return (ptr);
	ft_memcpy(res, ptr, old_size);
	free(ptr);
	return (res);
}

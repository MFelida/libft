/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:44:23 by mfelida           #+#    #+#             */
/*   Updated: 2023/12/04 13:44:32 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

#include <stdint.h>
#include <stdlib.h>

static size_t	_vector_extend(t_vector *v);

t_vector	*vector_new(size_t n_elem, size_t elem_size)
{
	t_vector	*res;

	if (!elem_size || SIZE_MAX / elem_size <= n_elem)
		return (NULL);
	res = malloc(sizeof(t_vector));
	if (!res)
		return (NULL);
	if (n_elem)
		res->cap = n_elem;
	else
		res->cap = 1;
	res->data = malloc(res->cap * elem_size);
	if (!res->data)
	{
		free(res);
		return (NULL);
	}
	res->size = 0;
	res->elem_size = elem_size;
	return (res);
}

size_t	vector_pushback(t_vector *v, void *new_data)
{
	if (!v || !new_data)
		return (0);
	if (v->size >= v->cap && _vector_extend(v) <= v->size)
		return (v->size);
	ft_memmove(v->data + v->size * v->elem_size, new_data, v->elem_size);
	v->size++;
	return (v->size);
}

const void	*vector_at(const t_vector *const v, size_t idx)
{
	if (!v || idx >= v->size)
		return (NULL);
	return (v->data + idx * v->elem_size);
}

void	vector_free(t_vector **v)
{
	if (!*v)
		return ;
	free((*v)->data);
	free(*v);
	*v = NULL;
	return ;
}

static size_t	_vector_extend(t_vector *v)
{
	void	*temp;

	if (!v)
		return (0);
	temp = malloc(2 * v->cap * v->elem_size);
	if (!temp)
		return (v->cap);
	ft_memmove(temp, v->data, v->size * v->elem_size);
	free(v->data);
	v->data = temp;
	v->cap *= 2;
	return (v->cap);
}

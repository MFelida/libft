/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:38:28 by mfelida           #+#    #+#             */
/*   Updated: 2024/01/28 15:10:00 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	cap;
}	t_string;

typedef struct s_ring_buffer
{
	char	data[GNL_BUFFER_SIZE];
	ssize_t	ridx;
	ssize_t	widx;
	char	full;
}	t_ring_buffer;

size_t	rb_read(t_ring_buffer *rb, char *dest)
{
	size_t	res;
	char	last;

	res = 0;
	last = 0;
	while (!(!((*rb).full) && ((*rb).ridx == (*rb).widx)))
	{
		*dest = rb->data[rb->ridx];
		last = *dest;
		((rb->ridx) = ((rb->ridx + 1) % GNL_BUFFER_SIZE));
		rb->full = 0;
		res++;
		dest++;
		if (last == '\n')
			break ;
	}
	*dest = '\0';
	return (res);
}

ssize_t	rb_read_file(t_ring_buffer *rb, int fd)
{
	char	buff[GNL_BUFFER_SIZE];
	ssize_t	ret;
	ssize_t	i;

	ret = read(fd, buff, GNL_BUFFER_SIZE);
	if (ret <= 0)
		return (ret);
	i = 0;
	while (i < ret)
	{
		rb->data[rb->widx] = buff[i++];
		((rb->widx) = ((rb->widx + 1) % GNL_BUFFER_SIZE));
		if (rb->full)
			rb->ridx = rb->widx;
		if ((!((*rb).full) && ((*rb).ridx == (*rb).widx)))
			rb->full = 1;
	}
	return (ret);
}

void	extend_str(t_string *s, t_ring_buffer *rb, ssize_t len)
{
	char	*temp;

	if (len < 0)
	{
		free(s->str);
		s->str = NULL;
		return ;
	}
	if (len + s->len > s->cap)
	{
		s->cap *= 2;
		temp = malloc((s->cap + 1) * sizeof (char));
		if (!temp)
		{
			free(s->str);
			s->str = NULL;
			return ;
		}
		ft_strlcpy(temp, s->str, s->len + 1);
		free(s->str);
		s->str = temp;
	}
	if (!(s->str))
		return ;
	s->len += rb_read(rb, s->str + s->len);
}

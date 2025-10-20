/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:38:30 by mfelida           #+#    #+#             */
/*   Updated: 2024/02/05 13:28:35 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	extend_str(t_string *s, t_ring_buffer *rb, ssize_t len);
size_t	rb_read(t_ring_buffer *rb, char *dest);
ssize_t	rb_read_file(t_ring_buffer *rb, int fd);

char	*ft_gnl(int fd)
{
	static t_ring_buffer	rb = {0};
	t_string				res;
	ssize_t					ret;

	ret = GNL_BUFFER_SIZE;
	if (!((rb).full) && ((rb).ridx == (rb).widx))
	{
		ret = rb_read_file(&rb, fd);
		if (ret <= 0)
			return (NULL);
	}
	res.cap = GNL_BUFFER_SIZE;
	res.str = (char *) malloc((res.cap + 1) * sizeof(char));
	if (!(res.str))
		return (NULL);
	res.len = rb_read(&rb, res.str);
	while ((!((rb).full) && ((rb).ridx == (rb).widx))
		&& ret == GNL_BUFFER_SIZE && res.str[res.len - 1] != '\n')
	{
		ret = rb_read_file(&rb, fd);
		extend_str(&res, &rb, ret);
		if (res.str == NULL)
			return (NULL);
	}
	return (res.str);
}

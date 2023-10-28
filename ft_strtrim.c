/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:19:39 by mfelida           #+#    #+#             */
/*   Updated: 2023/10/20 13:00:21 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		len;
	char	*t;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (ft_strlen(s1) == 0)
		len = 0;
	else
	{
		t = ((char *)s1) + ft_strlen(s1) - 1;
		while (t > s1 && ft_strchr(set, *t))
			t--;
		len = t - s1;
	}
	res = ft_substr(s1, 0, len + 1);
	return (res);
}

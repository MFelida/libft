/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:19:39 by mfelida           #+#    #+#             */
/*   Updated: 2023/10/26 11:47:49 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static size_t	_ft_wordcount(char const *s, char c);
static size_t	_ft_wordlen(char const *s, char c);
static char		*_ft_strndup(char const *s, size_t n);
static void		*_free_split(char ***split);

char	**ft_split(char const *s, char c)
{
	char		**res;
	size_t		words;
	size_t		len;
	size_t		i;

	words = _ft_wordcount(s, c);
	res = malloc((words + 1) * sizeof (char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (words-- > 0)
	{
		while (*s && *s == c)
			s++;
		len = _ft_wordlen(s, c);
		res[i] = _ft_strndup(s, len);
		if (!(res[i++]))
			return (_free_split(&res));
		s += len;
	}
	res[i] = NULL;
	return (res);
}

static size_t	_ft_wordcount(char const *s, char c)
{
	size_t	res;

	if (s == NULL)
		return (0);
	res = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			res++;
		while (*s && *s != c)
			s++;
	}
	return (res);
}

static size_t	_ft_wordlen(char const *s, char c)
{
	size_t	res;

	res = 0;
	while (*s && *s++ != c)
		res++;
	return (res);
}

static char	*_ft_strndup(const char *s, size_t n)
{
	char	*res;

	if (ft_strlen(s) < n)
		n = ft_strlen(s);
	res = malloc(n + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s, n + 1);
	return (res);
}

static void	*_free_split(char ***split)
{
	char	**temp;

	temp = *split;
	while (**split)
	{
		free(**split);
		(*split)++;
	}
	free(temp);
	return (NULL);
}

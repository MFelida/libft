/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifelida <mifelida@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:03:00 by mifelida          #+#    #+#             */
/*   Updated: 2025/08/20 17:02:43 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit.h"
#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

static t_before_exit	*g_before_exit = NULL;

int	ft_atexit(void (*func)(void))
{
	t_before_exit	*node;

	node = malloc(sizeof(t_before_exit));
	if (!node)
		return (1);
	node->next = NULL;
	node->func = func;
	ft_lstadd_front((t_list **) &g_before_exit, (t_list *) node);
	return (0);
}

static void	_do_func(void *node)
{
	((t_before_exit *)node)->func();
}

_Noreturn void	ft_exit(int status)
{
	ft_lstiter((t_list *) g_before_exit, _do_func);
	ft_lstclear((t_list **) &g_before_exit, free);
	exit(status);
}

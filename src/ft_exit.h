/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifelida <mifelida@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:02:29 by mifelida          #+#    #+#             */
/*   Updated: 2025/08/20 15:02:30 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXIT_H
# define FT_EXIT_H

typedef struct s_before_exit
{
	struct s_before_exit	*next;
	void					(*func)(void);
}	t_before_exit;

#endif	// FT_EXIT_H

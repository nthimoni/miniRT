/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:03:15 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/04 14:56:57 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"
#include "libft.h"
#include "miniRT.h"

void	exit_rt(t_rt *rt, char *error_msg, int exit_code)
{
	free_trash(rt->trash);
	(void)rt->trash;
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	exit(exit_code);

}

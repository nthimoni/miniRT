/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:03:15 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/05 19:05:20 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exit_rt.h"
#include "trash.h"

void	exit_rt(t_rt *rt, char *error_msg, int exit_code)
{
	free_trash(rt->trash);
	(void)rt->trash;
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	exit(exit_code);

}

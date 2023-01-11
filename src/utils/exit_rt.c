/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:03:15 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/11 22:09:15 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_rt.h"

void	exit_rt(t_rt *rt, char *error_msg, int exit_code)
{
	(void)rt->trash;
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	exit(exit_code);

}

void	exit_parsing(t_rt *rt, char *error_msg, int exit_code)
{
	(void)rt->trash;
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	exit(exit_code);
}

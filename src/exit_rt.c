/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:03:15 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/03 18:07:43 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"
#include "libft.h"

void	exit_rt(t_list* trash, char *error_msg, int exit_code)
{
	free_trash(trash);
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	exit(exit_code);

}

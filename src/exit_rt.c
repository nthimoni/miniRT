/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:03:15 by nthimoni          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/04 14:56:57 by rmorel           ###   ########.fr       */
=======
/*   Updated: 2022/10/05 14:19:43 by rmorel           ###   ########.fr       */
>>>>>>> 4a1ab7445df60f748c384842dd0dfa9774244b51
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
#include "miniRT.h"
=======
#include "exit_rt.h"
#include "trash.h"
>>>>>>> 4a1ab7445df60f748c384842dd0dfa9774244b51

void	exit_rt(t_rt *rt, char *error_msg, int exit_code)
{
	free_trash(rt->trash);
	(void)rt->trash;
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	exit(exit_code);

}

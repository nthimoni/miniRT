/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:54:33 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/04 17:24:55 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

int	main(void)
{
	t_rt	*rt;

	rt = NULL;
	ft_printf("Hello World!\n");
	rt = init_rt();
	clear_image(rt);
	test(rt);
	(void)rt;
	mlx_loop(rt->mlx);
	return (0);
}

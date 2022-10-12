/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:54:33 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/12 18:11:50 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "test.h"
#include "ray.h"

int	main(void)
{
	t_rt	*rt;
	t_intersect inter[W_W][W_H];

	rt = NULL;
	ft_printf("Hello World!\n");
	rt = init_rt();
	init_inter(rt, inter);
	clear_image(rt);
	(void)rt;
	mlx_loop(rt->mlx);
	ft_split("ok", ' ');
	return (0);
}

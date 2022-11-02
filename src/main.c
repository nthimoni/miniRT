/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:54:33 by nthimoni          #+#    #+#             */
/*   Updated: 2022/11/02 19:04:55 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "init.h"
#include "mlx.h"
#include "test.h"
#include "ray.h"
#include "data_struct.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_rt	*rt;

	/*float a = 10;
	if (ft_atof("1", &a))
		ft_printf("OVERFLOW\n\n");
	printf("val : %f\n", a);
	if (ft_atof("0.8", &a))
		ft_printf("OVERFLOW\n\n");
	printf("val : %f\n", a);
	if (ft_atof("0.9", &a))
		ft_printf("OVERFLOW\n\n");
	printf("val : %f\n", a);
	ft_printf("Hello World!\n");*/
	rt = NULL;
	rt = init_rt();
	if (argc > 1)
		parsing(rt, argv[1], &rt->scn);
	init_inter(rt);
	mlx_hook(rt->win, 17, 1<<17, red_cross, rt);
	mlx_hook(rt->win, 2, 1L << 0, key_hook, rt);
	mlx_mouse_hook(rt->win, mouse_hook, rt);
	mlx_loop(rt->mlx);
	return (0);
}

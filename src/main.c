/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:54:33 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/11 18:56:22 by rmorel           ###   ########.fr       */
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

	rt = NULL;
	rt = init_rt();
	if (argc > 1)
		parsing(rt, argv[1], &rt->scn);
	init_inter(rt);
	mlx_hook(rt->win, 17, 1 << 17, red_cross, rt);
	mlx_hook(rt->win, 2, 1L << 0, key_hook, rt);
	mlx_mouse_hook(rt->win, mouse_hook, rt);
	mlx_loop(rt->mlx);
	return (0);
}

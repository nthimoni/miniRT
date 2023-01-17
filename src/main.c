/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:54:33 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/17 00:53:18 by nthimoni         ###   ########.fr       */
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

	if (argc == 1)
		return (1);
	rt = NULL;
	rt = init_rt();
	argv++;
	while (*argv)
	{
		ft_printf("input file : %s\n", *argv);
		rt->scn.objs = NULL;
		rt->scn.light = NULL;
		parsing(rt, *argv, &rt->scn);
		init_inter(rt);
		free_scene(rt);
		argv++;
	}
	mlx_hook(rt->win, 17, 1 << 17, red_cross, rt);
	mlx_hook(rt->win, 2, 1L << 0, key_hook, rt);
	mlx_mouse_hook(rt->win, mouse_hook, rt);
	mlx_loop(rt->mlx);
	exit_rt(rt);
	return (0);
}

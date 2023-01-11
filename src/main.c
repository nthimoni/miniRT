/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:54:33 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/11 21:50:54 by rmorel           ###   ########.fr       */
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
	rt->text.img = mlx_xpm_file_to_image(rt->mlx, "earth.xpm", &rt->text.x, &rt->text.y);
	rt->text.addr = mlx_get_data_addr(rt->text.img, &rt->text.bpp, &rt->text.line_lgth, &rt->text.endian);
	rt->bump.img = mlx_xpm_file_to_image(rt->mlx, "bump.xpm", &rt->bump.x, &rt->bump.y);
	rt->bump.addr = mlx_get_data_addr(rt->bump.img, &rt->bump.bpp, &rt->bump.line_lgth, &rt->bump.endian);
	mlx_put_image_to_window(rt->mlx, rt->win, rt->bump.img, 0, 0);

	init_inter(rt);
	ft_printf("rendered\n");
	mlx_hook(rt->win, 17, 1 << 17, red_cross, rt);
	mlx_hook(rt->win, 2, 1L << 0, key_hook, rt);
	mlx_mouse_hook(rt->win, mouse_hook, rt);
	mlx_loop(rt->mlx);
	return (0);
}

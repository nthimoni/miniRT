/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:15 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/01 14:33:20 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "lighting.h"

void	init_inter(t_rt *rt)
{
	world_to_camera(rt);
	//print_axis(rt);
	fill_matrix_obj(rt);
	test_wtoo(rt);
	// rt-space défini dans quel espace on va faire les calculs
	rt->space = WORLD;
	rt->debug = FALSE;
	init_pixel(rt);
	rt->debug = TRUE;
	//init_pixel_debug(rt);
	clear_image(rt);
}

void	init_pixel(t_rt *rt)
{
	t_intersect	inter;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < W_W)
	{
		while (j < W_H)
		{
			if (i == 1548 && j == 208)
			{
				printf("Eh le schtroumpf, vient ici !\n");
				printf("scalarFOV = %lf\n", tan(rt->scn.cam.FOV / 2));
			}
			ft_bzero(&inter, sizeof(t_intersect));
			inter.t0 = DBL_MAX;
			inter.t1 = DBL_MAX;
			pixel_raster_to_space(&inter, i, j, rt);
			intersect_obj(rt, &inter);
			if (inter.t0 < DBL_MAX)
			{
				if (i == 966 && j == 541)
					ft_printf("PAUSE\n");
				my_mlx_pixel_put(rt, i, j, lighting(rt, &inter));
			}
			j++;
		}
		j = 0;
		i++;
	}
	printf("Ca n'compte quand meme que pourrrr un !\n");
}

void	intersect_obj(t_rt *rt, t_intersect *inter)
{
	t_list	*tmp;

	tmp = rt->scn.objs;
	while (tmp)
	{
		if (inter->obj_ign != tmp->content)
		{	
			if (((t_obj *)tmp->content)->type == SPHERE)
			{
				if (rt->space == WORLD)
					intersect_sph(tmp->content, inter, inter->ray);
				else if (rt->space == OBJ)
					intersect_sph2(tmp->content, inter, inter->ray);
			}
			else if (((t_obj *)tmp->content)->type == PLAN)
				intersect_plane(tmp->content, inter, inter->ray);
			else if (((t_obj *)tmp->content)->type == CYLINDRE)
				intersect_cylinder(tmp->content, inter, inter->ray);
			else if (((t_obj *)tmp->content)->type == CONE)
				intersect_cone(tmp->content, inter, inter->ray);
		}
		tmp = tmp->next;
	}
}

t_u	abs_u(t_u n)
{
	if (n < 0)
		return (-n);
	return (n);
}

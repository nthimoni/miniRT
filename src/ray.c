/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:15 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/26 19:53:58 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	init_inter(t_rt *rt)
{
	world_to_camera(rt);
	print_axis(rt);
	fill_matrix_obj(rt);
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
			if (i == 868 && j == 440)
				printf("Eh le schtroumpf, vient ici !\n");
			ft_bzero(&inter, sizeof(t_intersect));
			inter.t0 = DBL_MAX;
			inter.t1 = DBL_MAX;
			pixel_raster_to_space(&inter, i, j, rt);
			intersect_obj(rt, &inter, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	printf("Ca n'compte quand meme que pourrrr un !\n");
}

void	intersect_obj(t_rt *rt, t_intersect *inter, int i, int j)
{
	t_list	*tmp;

	tmp = rt->scn.objs;
	while (tmp)
	{
		if (((t_obj *)tmp->content)->type == SPHERE)
		{
			if (rt->space == WORLD)
				intersect_sph(tmp->content, inter);
			else if (rt->space == OBJ)
				intersect_sph2(tmp->content, inter);
		}
		else if (((t_obj *)tmp->content)->type == PLAN)
			intersect_plane(tmp->content, inter);
		tmp = tmp->next;
	}
	if (inter->t0 < DBL_MAX)
		my_mlx_pixel_put(rt, i, j, inter->obj->color);
}

void	intersect_plane(t_obj *plane, t_intersect *inter)
{
	if (abs_u(inter->ray.d.y) < EPS)
		return ;
	inter->t0_tmp = -inter->ray.o.y / inter->ray.d.y;
	if (inter->t0_tmp >= inter->t0 || inter->t0_tmp < 0)
		return ;
	inter->obj = plane;
	inter->t0 = inter->t0_tmp;
	inter->t1 = DBL_MAX;
}

t_u	abs_u(t_u n)
{
	if (n < 0)
		return (-n);
	return (n);
}

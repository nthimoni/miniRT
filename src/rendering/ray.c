/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:15 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 16:27:39 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "lighting.h"

void	init_inter(t_rt *rt)
{
	world_to_camera(rt);
	fill_matrix_obj(rt);
	rt->space = OBJ;
	rt->debug = FALSE;
	if (rt->aa.anti_aliasing)
		init_pixel_aa(rt);
	else
		init_pixel(rt);
	rt->debug = TRUE;
	clear_image(rt);
}

void	init_pixel_aa(t_rt *rt)
{
	int			i_j[2];

	i_j[0] = 0;
	i_j[1] = 0;
	while (i_j[0] < W_W)
	{
		while (i_j[1] < W_H)
		{
			draw_pixel_aa(i_j, rt);		
			i_j[1]++;
		}
		i_j[1] = 0;
		i_j[0]++;
	}
}

void	draw_pixel_aa(int i_j[2], t_rt *rt)
{
	t_color			color;
	int				res;
	t_intersect		inter;
	double			rand_n;
	unsigned int	count;

	ft_bzero(&color, sizeof(t_color));;
	count = 0;
	while (count++ < rt->aa.n)
	{
		rand_n = ((double)rand()) / RAND_MAX - 0.5;
		ft_bzero(&inter, sizeof(t_intersect));
		inter.t0 = DBL_MAX;
		inter.t1 = DBL_MAX;
		pixel_raster_to_space(&inter, i_j[0] + rand_n, i_j[1] + rand_n, rt);
		intersect_obj(rt, &inter);
		res = lighting(rt, &inter);
		color.t += get_t(res);
		color.r += get_r(res);
		color.g += get_g(res);
		color.b += get_b(res);
	}
	my_mlx_pixel_put(rt, i_j[0], i_j[1], create_trgb(color.t / rt->aa.n, color.r / rt->aa.n, color.g / rt->aa.n, color.b / rt->aa.n));
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
			if (i == 810 && j == 505)
				printf("Eh le schtroumpf, vient ici !\n");
			ft_bzero(&inter, sizeof(t_intersect));
			inter.t0 = DBL_MAX;
			inter.t1 = DBL_MAX;
			pixel_raster_to_space(&inter, i, j, rt);
			intersect_obj(rt, &inter);
			if (inter.t0 < DBL_MAX)
				my_mlx_pixel_put(rt, i, j, lighting(rt, &inter));
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

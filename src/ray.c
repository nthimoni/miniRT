/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:15 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/12 18:13:02 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "ray.h"
#include "matrix.h"
#include "transformations.h"
#include "print.h"
#include "test.h"
#include "vector.h"

void	create_ray(t_ray *new, t_tuple p, t_tuple v)
{
	new->o.x = p.x;
	new->o.y = p.y;
	new->o.z = p.z;
	new->o.w = p.w;
	new->d.x = v.x;
	new->d.y = v.y;
	new->d.z = v.z;
	new->d.w = v.w;
}

void	position(t_tuple *new, t_ray r, t_tuple p)
{
	new->x = p.x * r.d.x + r.o.x;
	new->y = p.y * r.d.y + r.o.y;
	new->z = p.z * r.d.z + r.o.z;
	new->w = 0;
}

void	init_inter(t_rt *rt, t_intersect inter[W_W][W_H])
{
	world_to_camera(rt);
	init_pixel(rt, inter);
	init_rays(inter, rt);
}

void	init_pixel(t_rt *rt, t_intersect inter[W_W][W_H])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < W_W)
	{
		while (j++ < W_H)
			pixel_raster_to_space(&inter[i][j], i, j, rt);
		j = 0;
		i++;
	}
}

void	world_to_camera(t_rt *rt)
{
	t_u	rot_y;
	t_u	rot_z;
	t_u	rot_y_m4[4][4];
	t_u	rot_z_m4[4][4];
	t_u	trans_m4[4][4];
	t_u	tmp[4][4];

	rot_y = M_PI - atan(rt->cam_d.x / rt->cam_d.z);
	rot_z = atan(rt->cam_d.y / rt->cam_d.x);
	rot_y_matrix_4(rot_y_m4, - rot_y);
	rot_z_matrix_4(rot_z_m4, rot_z);
	trans_matrix_4(trans_m4, rt->cam_o.x, rt->cam_o.y, rt->cam_o.z);
	mult_matrix_4(tmp, rot_z_m4, rot_y_m4);
	mult_matrix_4(rt->ctow_m, trans_m4, tmp);
	invert_matrix_4(rt->ctow_m, rt->wtoc_m);
	test_world_matrix(rt);
}

void	init_rays(t_intersect inter[W_W][W_H], t_rt *rt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < W_W)
	{
		while (j++ < W_H)
		{
			inter[i][j].ray.o.x = inter[i][j].pixel.x;
			inter[i][j].ray.o.y = inter[i][j].pixel.y;
			inter[i][j].ray.o.z = inter[i][j].pixel.z;
			inter[i][j].ray.o.w = 1;
			inter[i][j].ray.d.x = inter[i][j].pixel.x;
			inter[i][j].ray.d.y = inter[i][j].pixel.y;
			inter[i][j].ray.d.z = inter[i][j].pixel.z;
			inter[i][j].ray.d.x = 0;
			mult_tuple_matrix_4(&inter[i][j].ray.o, rt->ctow_m, inter[i][j].ray.o);
			mult_tuple_matrix_4(&inter[i][j].ray.d, rt->ctow_m, inter[i][j].ray.d);
			norm_v3(&inter[i][j].ray.d);
			print_tuple(&inter[i][j].ray.d, "Pix_d");
		}
		j = 0;
		i++;
	}
}

//	Pour l'instant que si C est a l'origine et le plan sur le point (0, 0, 1)
void	pixel_raster_to_space(t_intersect *i, int x, int y, t_rt *rt)
{
	i->pixel.x = (x + 0.5) / W_W;
	i->pixel.y = (y + 0.5) / W_H;
	if (i->pixel.x > 0.5)
		i->pixel.x = 2 * i->pixel.x - 1;
	else
		i->pixel.x = 1 - 2 * i->pixel.x;
	if (i->pixel.y > 0.5)
		i->pixel.y = 2 * i->pixel.y - 1;
	else
		i->pixel.y = 1 - 2 * i->pixel.y;
	i->pixel.x = (2 * i->pixel.x - 1) * W_W / W_H * tan(rt->angle / 2);	
	i->pixel.y = (2 * i->pixel.y - 1) * tan(rt->angle / 2);	
	i->pixel.z = -1;
	i->pixel.w = 1;
}

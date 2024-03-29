/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:49:21 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/19 04:13:07 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	get_matrix_align_v1_v2(t_u m[4][4], t_tuple v1, t_tuple v2)
{
	t_tuple	u;
	t_u		cos_a;
	t_u		k;

	u = cross_product_v3(v1, v2);
	cos_a = dot_product_v3(v1, v2);
	k = 1.0 / (1.0 + cos_a);
	m[0][0] = u.x * u.x * k + cos_a;
	m[0][1] = u.y * u.x * k - u.z;
	m[0][2] = u.z * u.x * k + u.y;
	m[0][3] = 0;
	m[1][0] = u.x * u.y * k + u.z;
	m[1][1] = u.y * u.y * k + cos_a;
	m[1][2] = u.z * u.y * k - u.x;
	m[1][3] = 0;
	m[2][0] = u.x * u.z * k - u.y;
	m[2][1] = u.y * u.z * k + u.x;
	m[2][2] = u.z * u.z * k + cos_a;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

t_bool	check_vector_opposite(t_tuple v1, t_tuple v2)
{
	norm_v3(&v1);
	norm_v3(&v2);
	if ((v1.x == -v2.x) && (v1.y == -v2.y) && (v1.z == -v2.z) && (v1.w == v2.w))
		return (TRUE);
	return (FALSE);
}

void	fill_matrix_obj(t_rt *rt)
{
	t_list			*tmp;
	t_obj			*obj;
	t_obj_matrix	m;

	tmp = rt->scn.objs;
	while (tmp)
	{
		ft_bzero(&m, sizeof(t_obj_matrix));
		obj = (t_obj *)tmp->content;
		norm_v3(&obj->d);
		ft_bzero(&obj->wtoo_m, sizeof(t_u[4][4]));
		ft_bzero(&obj->otow_m, sizeof(t_u[4][4]));
		if (obj->type == SPHERE)
			sphere_matrix(m, obj);
		else if (obj->type == PLAN)
			plan_matrix(m, obj);
		else if (obj->type == CYLINDRE)
			cylinder_matrix(m, obj);
		else if (obj->type == CONE)
			cone_matrix(m, obj);
		tmp = tmp->next;
	}
}

void	world_to_camera(t_rt *rt)
{
	t_u		trans_m4[4][4];
	t_u		tmp[4][4];
	t_tuple	cam_space;

	cam_space.x = 0;
	cam_space.y = 0;
	cam_space.z = 1;
	cam_space.w = 0;
	ft_bzero(&rt->ctow_m, sizeof(t_u[4][4]));
	ft_bzero(&rt->wtoc_m, sizeof(t_u[4][4]));
	norm_v3(&cam_space);
	norm_v3(&rt->scn.cam.d);
	if (check_vector_opposite(cam_space, rt->scn.cam.d))
		rot_y_matrix_4(tmp, M_PI);
	else
		get_matrix_align_v1_v2(tmp, cam_space, rt->scn.cam.d);
	trans_matrix_4(trans_m4, rt->scn.cam.o.x, rt->scn.cam.o.y, rt->scn.cam.o.z);
	mult_matrix_4(rt->ctow_m, trans_m4, tmp);
	invert_matrix_4(rt->ctow_m, rt->wtoc_m);
}

void	pixel_raster_to_space(t_intersect *i, t_u x, t_u y, t_rt *rt)
{
	t_u	angle;

	angle = tan(rt->scn.cam.fov / 2 * M_PI / 180);
	i->pixel.x = (2 * (x + 0.5) / W_W - 1) * W_W / W_H * angle;
	i->pixel.y = (1 - 2 * (y + 0.5) / W_H) * angle;
	i->pixel.z = 1;
	i->pixel.w = 1;
	ft_bzero(&i->ray.o, sizeof(t_tuple));
	i->ray.o.x = 0;
	i->ray.o.y = 0;
	i->ray.o.z = 0;
	i->ray.o.w = 1;
	i->ray.d.x = i->pixel.x - 0;
	i->ray.d.y = i->pixel.y - 0;
	i->ray.d.z = i->pixel.z - 0;
	i->ray.d.w = 0;
	mult_tuple_matrix_4(&i->ray.o, rt->ctow_m, i->ray.o);
	mult_tuple_matrix_4(&i->ray.d, rt->ctow_m, i->ray.d);
	norm_v3(&i->ray.d);
}

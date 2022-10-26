/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:49:21 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/26 19:30:21 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "scene.h"

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
	t_list	*tmp;
	t_obj	*obj;
	t_u		scale_m[4][4];
	t_u		trans_m[4][4];

	tmp = rt->scn.objs;
	while (tmp)
	{
		ft_bzero(scale_m, sizeof(t_u[4][4]));
		ft_bzero(trans_m, sizeof(t_u[4][4]));
		obj = (t_obj *)tmp->content;
		ft_bzero(&obj->wtoo_m, sizeof(t_u[4][4]));
		ft_bzero(&obj->otow_m, sizeof(t_u[4][4]));
		if (obj->type == SPHERE)
		{
			trans_matrix_4(trans_m, obj->o.x, obj->o.y, obj->o.z);
			scale_matrix_4(scale_m, obj->diam /2, obj->diam /2, obj->diam /2);
			mult_matrix_4(obj->otow_m, trans_m, scale_m);
			invert_matrix_4(obj->otow_m, obj->wtoo_m);
			print_matrix_4(obj->wtoo_m, "wtoo");
			print_matrix_4(obj->otow_m, "otow");
		}
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
	//test_world_matrix(rt);
}

void	world_to_camera2(t_rt *rt)
{
	t_u		rotx[4][4];
	t_u		roty[4][4];
	t_u		trans[4][4];
	t_u		tmp[4][4];
	t_u		alpha;
	t_u		beta;
	t_u		hyp;

	ft_bzero(&rt->ctow_m, sizeof(t_u[4][4]));
	ft_bzero(&rt->wtoc_m, sizeof(t_u[4][4]));
	alpha = atan2(rt->scn.cam.d.x, rt->scn.cam.d.z);
	hyp = sqrt(pow(rt->scn.cam.d.x, 2) + pow(rt->scn.cam.d.z, 2));
	beta = atan2(rt->scn.cam.d.y, hyp);
	norm_v3(&rt->scn.cam.d);
	rot_y_matrix_4(roty, alpha);
	rot_x_matrix_4(rotx, -beta);
	mult_matrix_4(tmp, roty, rotx);
	trans_matrix_4(trans, -rt->scn.cam.o.x, -rt->scn.cam.o.y, -rt->scn.cam.o.z);
	mult_matrix_4(rt->wtoc_m, trans, tmp);
	invert_matrix_4(rt->wtoc_m, rt->ctow_m);
}

void	pixel_raster_to_space(t_intersect *i, int x, int y, t_rt *rt)
{
	i->pixel.x = (x + 0.5) / W_W;
	i->pixel.y = (y + 0.5) / W_H;
	i->pixel.x = 2 * i->pixel.x - 1;
	i->pixel.y = 1 - 2 * i->pixel.y;
	i->pixel.x = i->pixel.x * W_W / W_H * tan(rt->scn.cam.FOV / 2);	
	i->pixel.y = i->pixel.y * tan(rt->scn.cam.FOV / 2);	
	i->pixel.z = 1;
	i->pixel.w = 1;
	i->ray.o.x = 0;
	i->ray.o.y = 0;
	i->ray.o.z = 0;
	i->ray.o.w = 1;
	i->ray.d.x = i->pixel.x - 0;
	i->ray.d.y = i->pixel.y - 0;
	i->ray.d.z = i->pixel.z - 0;
	i->ray.d.w = 0;
	if (rt->debug)
	{
		print_tuple(&i->ray.o, "ray_o in camera space");
		print_tuple(&i->ray.d, "ray_d in camera space");
	}
	mult_tuple_matrix_4(&i->ray.o, rt->ctow_m, i->ray.o);
	mult_tuple_matrix_4(&i->ray.d, rt->ctow_m, i->ray.d);
	if (rt->debug)
	{
		print_tuple(&i->ray.o, "ray_o * ctow");
		print_tuple(&i->ray.d, "ray_d * ctow");
	}
	norm_v3(&i->ray.d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:53:04 by rmorel            #+#    #+#             */
/*   Updated: 2022/12/02 19:41:33 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// Malloc les vecteurs et les add to trashi, utiliser des pointeurs

t_tuple	create_tuple(t_u *array)
{
	t_tuple	new;

	new.x = array[0];
	new.y = array[1];
	new.z = array[2];
	new.w = array[3];
	return (new);
}

t_tuple	create_tuple_pts(int x, int y, int z, int w)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = w;
	return (new);
}

t_tuple	create_null_tuple(void)
{
	t_tuple	new;

	new.x = 0;
	new.y = 0;
	new.z = 0;
	new.w = 0;
	return (new);
}

t_tuple	create_v3(t_tuple p1, t_tuple p2)
{
	t_tuple	new;

	new.x = p2.x - p1.x;
	new.y = p2.y - p1.y;
	new.z = p2.z - p1.z;
	new.w = p2.w - p1.w;
	return (new);
}

t_tuple	create_tuple_copy(t_tuple t)
{
	t_tuple	new;

	new.x = t.x;
	new.y = t.y;
	new.z = t.z;
	new.w = t.w;
	return (new);
}

t_tuple	add_tupple(t_tuple t1, t_tuple t2)
{
	t_tuple	new;

	new.x = t2.x + t1.x;
	new.y = t2.y + t1.y;
	new.z = t2.z + t1.z;
	new.w = 0;
	if (t1.w && t2.w)
		ft_printf("ERROR : add_tupple with 2 points\n");
	else if (t1.w || t2.w)
		new.w = 1;
	else
		new.w = 0;
	return (new);
}

t_tuple	sub_tupple(t_tuple t1, t_tuple t2)
{
	t_tuple	new;

	new.x = t2.x - t1.x;
	new.y = t2.y - t1.y;
	new.z = t2.z - t1.z;
	new.w = 0;
	return (new);
}

t_tuple	neg_tupple(t_tuple t)
{
	t_tuple	new;

	new.x = -t.x;
	new.y = -t.y;
	new.z = -t.z;
	new.w = t.z;
	return (new);
}

void	scale_v3(t_tuple *v1, t_u s)
{
	v1->x *= s;
	v1->y *= s;
	v1->z *= s;
}

t_u	length_v3(t_tuple v)
{
	t_u	d;

	if (v.w > 1 - EPS && v.w < 1 + EPS)
	{
		ft_putstr_fd("Add_v3 parami's is a point\n", 2);
		return (0);
	}
	d = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (d);
}

void	norm_v3(t_tuple *v)
{
	t_u	l;

	l = length_v3(*v);
	if (!l)
		return ;
	v->x /= l;
	v->y /= l;
	v->z /= l;
}

t_u	dot_product_v3(t_tuple v1, t_tuple v2)
{
	t_u	d;
	t_u		onep;
	t_u		onem;

	onep = 1 + EPS;
	onem = 1 - EPS;
	if ((v1.w > onem && v1.w < onep) || (v2.w > onem && v2.w < onep))
	{
		ft_putstr_fd("Cross_product_v3 param's is a point", 2);
		return (0);
	}
	d = v2.x * v1.x + v2.y * v1.y + v2.z * v1.z;
	return (d);
}

t_tuple	cross_product_v3(t_tuple v1, t_tuple v2)
{
	t_tuple	new;
	t_u		onep;
	t_u		onem;

	onep = 1 + EPS;
	onem = 1 - EPS;
	if ((v1.w > onem && v1.w < onep) || (v2.w > onem && v2.w < onep))
		ft_putstr_fd("Cross_product_v3 param's is a point", 2);
	new.x = v1.y * v2.z - v1.z * v2.y;
	new.y = v1.z * v2.x - v1.x * v2.z;
	new.z = v1.x * v2.y - v1.y * v2.x;
	new.w = 0;
	return (new);
}

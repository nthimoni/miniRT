/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:56:57 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 15:41:32 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

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
	t_u	onep;
	t_u	onem;

	onep = 1 + EPS;
	onem = 1 - EPS;
	if ((v1.w > onem && v1.w < onep) || (v2.w > onem && v2.w < onep))
	{
		ft_putstr_fd("Dot_product_v3 param's is a point", 2);
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

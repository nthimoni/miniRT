/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:56:30 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 15:21:49 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_tuple	add_tupple(t_tuple t1, t_tuple t2)
{
	t_tuple	new;

	new.x = t2.x + t1.x;
	new.y = t2.y + t1.y;
	new.z = t2.z + t1.z;
	new.w = 0;
	if (t1.w && t2.w)
		ft_putstr_fd("ERROR : add_tupple with 2 points\n", 2);
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
	if (t2.w == 0 && t1.w)
		ft_putstr_fd("ERROR : Substracting point to vector.\n", 2);
	new.w = 0;
	return (new);
}

t_tuple	neg_tupple(t_tuple t)
{
	t_tuple	new;

	new.x = -t.x;
	new.y = -t.y;
	new.z = -t.z;
	new.w = t.w;
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

	if (v.w > 1 + EPS && v.w < 1 - EPS)
	{
		ft_putstr_fd("Add_v3 parami's is a point\n", 2);
		return (0);
	}
	d = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (d);
}

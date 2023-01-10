/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:53:04 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 14:59:45 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_tuple	create_tuple(t_u *array)
{
	t_tuple	new;

	new.x = array[0];
	new.y = array[1];
	new.z = array[2];
	new.w = array[3];
	return (new);
}

t_tuple	create_tuple_pts(t_u x, t_u y, t_u z, t_u w)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	new.z = z;
	if (w != 1 && w != 0)
		ft_putstr_fd("Param w should be either 1 or 0.\n", 2);
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

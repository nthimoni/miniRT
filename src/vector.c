/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:53:04 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/03 18:19:39 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Malloc les vecteurs et les add to trashi, utiliser des pointeurs

t_tuple	*create_tuple(t_decimal *array)
{
	t_tuple	*new;

	new = malloc(sizeof(t_tuple));
	if (!new)
		return (NULL);
	new->x = array[0];
	new->y = array[1];
	new->z = array[2];
	new->w = array[3];
	return (new);
}

t_tuple	*create_null_tuple(void)
{
	t_tuple	*new;

	new = malloc(sizeof(t_tuple));
	if (!new)
		return (NULL);
	new->x = 0;
	new->y = 0;
	new->z = 0;
	new->w = 0;
	return (new);
}

t_vector3	add_v3(t_vector3 v1, t_vector3 v2)
{
	t_vector3	new;

	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	new.z = v1.z + v2.z;
	return (new);
}
void		scale_v3(t_vector3 *v1, t_decimal s)
{
	v1->x *= s;
	v1->y *= s;
	v1->z *= s;
}
t_decimal		length_v3(t_vector3 v1)
{
	t_decimal	d;

	d = ((v1.x^2) + (v1.y^2) + (v1.z^2))^(-2);
	return (d);
}

t_tuple	*create_vector(t_tuple *p1, t_tuple *p2)
{
	t_tuple	*new;

	new = create_null_tuple(void);
	new->x = p2->x - p1->x;
	v.y = p2.y - p1.y;
	v.z = p2.z - p1.z;
	return (v);
}
t_vector3	norm_v3(t_vector3 v)
{
	t_vector3	new;

	new = add_v3(v, NULL);
	scale_v3(new, 1 / length_v3(new));
	return (new);
}

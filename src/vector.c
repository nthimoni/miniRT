/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:53:04 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/04 16:25:52 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Malloc les vecteurs et les add to trashi, utiliser des pointeurs

t_tuple	*create_tuple(t_decimal *array, t_rt *rt)
{
	t_tuple	*new;

	new = malloc(sizeof(t_tuple));
	if (!new)
		exit_rt(rt, "MEM_ERR", 1);
	new->x = array[0];
	new->y = array[1];
	new->z = array[2];
	new->w = array[3];
	return (new);
}

t_tuple	*create_null_tuple(t_rt *rt)
{
	t_tuple	*new;

	new = malloc(sizeof(t_tuple));
	if (!new)
		exit_rt(rt, "MEM_ERR", 1);
	new->x = 0;
	new->y = 0;
	new->z = 0;
	new->w = 0;
	return (new);
}

t_tuple	*create_v3(t_tuple *p1, t_tuple *p2, t_rt *rt)
{
	t_tuple	*new;

	new = create_null_tuple(rt);
	new->x = p2->x - p1->x;
	new->y = p2->y - p1->y;
	new->z = p2->z - p1->z;
	new->w = p2->w - p1->w;
	return (new);
}

t_tuple	*create_tuple_copy(t_tuple *t, t_rt *rt)
{
	t_tuple	*new;

	new = create_null_tuple(rt);
	new->x = t->x;
	new->y = t->y;
	new->z = t->z;
	new->w = t->w;
	return (new);
}

t_tuple	*add_v3(t_tuple *v1, t_tuple *v2, t_rt *rt)
{
	t_tuple	*new;

	if (v1->w || v2->w)
	{
		ft_putstr_fd("Add_v3 param's is a point", 2);
		return (NULL);
	}
	new = create_null_tuple(rt);
	new->x = v2->x - v1->x;
	new->y = v2->y - v1->y;
	new->z = v2->z - v1->z;
	new->w = 0;
	return (new);
}

t_tuple	*neg_v3(t_tuple *v, t_rt *rt)
{
	t_tuple	*new;

	if (v->w)
	{
		ft_putstr_fd("Neg_v3 param's is a point", 2);
		return (NULL);
	}
	new = create_null_tuple(rt);
	new->x = -v->x;
	new->y = -v->y;
	new->z = -v->z;
	new->w = 0;
	return (new);
}

void	scale_v3(t_tuple *v1, t_decimal s)
{
	v1->x *= s;
	v1->y *= s;
	v1->z *= s;
}

t_decimal	length_v3(t_tuple *v)
{
	t_decimal	d;

	if (v->w)
	{
		ft_putstr_fd("Add_v3 parami's is a point", 2);
		return (0);
	}
	d = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	return (d);
}

t_tuple	*norm_v3(t_tuple *v, t_rt *rt)
{
	t_tuple	*new;

	new = create_tuple_copy(v, rt);
	scale_v3(new, 1 / length_v3(v));
	return (new);
}

t_decimal	dot_product_v3(t_tuple *v1, t_tuple *v2)
{
	t_decimal	d;

	if (v1->w || v2->w)
	{
		ft_putstr_fd("Dot_product_v3 param's is a point", 2);
		return (0);
	}
	d = v2->x * v1->x + v2->y * v1->y + v2->z * v1->z;
	return (d);
}
t_tuple	*cross_product_v3(t_tuple *v1, t_tuple *v2, t_rt *rt)
{
	t_tuple	*new;

	if (v1->w || v2->w)
	{
		ft_putstr_fd("Cross_product_v3 param's is a point", 2);
		return (NULL);
	}
	new = create_null_tuple(rt);
	new->x = v1->y * v2->z - v1->z * v2->y;
	new->y = v1->x * v2->z - v1->z * v2->x;
	new->z = v1->x * v2->y - v1->y * v2->x;
	new->w = 0;
	return (new);
}

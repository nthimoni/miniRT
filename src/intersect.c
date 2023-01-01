/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:55:29 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/01 13:56:36 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void add_inter0(t_intersect *i, t_obj *o, t_u t)
{
	if (t < i->t0 && t > 0)
	{
		i->t0 = t;
		i->obj = o;
	}
}

void add_inter1(t_intersect *i, t_obj *o, t_u t)
{
	if (t < i->t1 && t > 0)
	{
		i->t1 = t;
		i->obj = o;
	}
}


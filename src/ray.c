/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:15 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/11 11:29:18 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "ray.h"

void	create_ray(t_ray *new, t_tuple p, t_tuple v)
{
	ray->o.x = p.x;
	ray->o.y = p.y;
	ray->o.z = p.z;
	ray->o.w = p.w;
	ray->d.x = v.x;
	ray->d.y = v.y;
	ray->d.z = v.z;
	ray->d.w = v.w;
}

void	position(t_tuple *new, t_ray r, t_tuple p)
{
	new->x = p.x * r.d.x + r.o.x;
	new->y = p.y * r.d.y + r.o.y;
	new->z = p.z * r.d.z + r.o.z;
	new->w = 0;
}

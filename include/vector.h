/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:43:53 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/03 17:54:23 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H 

typedef double	t_decimal;

typedef struct	s_tuple
{
	t_decimal	x;
	t_decimal	y;
	t_decimal	z;
	t_decimal	w;
}	t_tuple;

t_vector3	add_v3(t_vector3 v1, t_vector3 v2);
void		scale_v3(t_vector3 *v1, t_decimal s);
t_decimal	length_v3(t_vector3 v1);
t_vector3	subst_v3(t_point3 p1, t_point3 p2);
t_vector3	norm_v3(t_vector3 v);

#endif 

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:43:53 by rmorel            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/04 16:18:18 by rmorel           ###   ########.fr       */
=======
/*   Updated: 2022/10/05 14:13:27 by rmorel           ###   ########.fr       */
>>>>>>> 4a1ab7445df60f748c384842dd0dfa9774244b51
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

# include "miniRT.h"

typedef double	t_decimal;

typedef struct	s_tuple
{
	t_decimal	x;
	t_decimal	y;
	t_decimal	z;
	t_decimal	w;
}	t_tuple;

t_tuple		*create_tuple(t_decimal *array, t_rt *rt);
t_tuple		*create_null_tuple(t_rt *rt);
t_tuple		*create_v3(t_tuple *p1, t_tuple *p2, t_rt *rt);
t_tuple		*create_tuple_copy(t_tuple *t, t_rt *rt);
t_tuple		*add_v3(t_tuple *v1, t_tuple *v2, t_rt *rt);
t_tuple		*neg_v3(t_tuple *v, t_rt *rt);
void		scale_v3(t_tuple *v1, t_decimal s);
t_decimal	length_v3(t_tuple *v);
t_tuple		*norm_v3(t_tuple *v, t_rt *rt);
t_decimal	dot_product_v3(t_tuple *v1, t_tuple *v2);
t_tuple		*cross_product_v3(t_tuple *v1, t_tuple *v2, t_rt *rt);

#endif 

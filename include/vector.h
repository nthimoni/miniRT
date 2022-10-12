/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:43:53 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/12 17:48:35 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

# include "miniRT.h"

t_tuple		create_tuple(t_u *array);
t_tuple		create_null_tuple(void);
t_tuple		create_v3(t_tuple p1, t_tuple p2);
t_tuple		create_tuple_copy(t_tuple t);
t_tuple		add_tupple(t_tuple t1, t_tuple t2);
t_tuple		sub_tupple(t_tuple t1, t_tuple t2);
t_tuple		neg_v3(t_tuple v);
void		scale_v3(t_tuple *v1, t_u s);
t_u			length_v3(t_tuple v);
void		norm_v3(t_tuple *v);
t_u			dot_product_v3(t_tuple v1, t_tuple v2);
t_tuple		cross_product_v3(t_tuple v1, t_tuple v2);

#endif 

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:02:04 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/03 13:14:09 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#define TEST_H 

# include "data_struct.h"
# include "print.h"
# include "matrix.h"
# include "vector.h"
# include "transformations.h"
# include <math.h>
# include "mlx.h"
# include "image.h"

typedef struct	s_proj
{
	t_tuple	position;
	t_tuple	velocity;
}	t_proj;

void		test(t_rt *rt);
void		test2(t_rt *rt);
t_proj		tick_environment(t_proj proj, t_tuple gravity, t_tuple wind);
void		test3(t_rt *rt);
void		test4(t_rt *rt);
void		print_point_test4(t_rt *rt, t_tuple pos);
void		test_world_matrix(t_rt *rt);
void	test_sphere_init(t_rt *rt);
t_obj	*create_sphere(int type, t_tuple origin, float diam, int color);
void	test_wtoo(t_rt *rt);
void	test_cone(void);


#endif 

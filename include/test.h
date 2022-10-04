/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:02:04 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/04 17:14:10 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#define TEST_H 

typedef struct	s_proj
{
	t_tuple	*position;
	t_tuple	*velocity;
}	t_proj;

t_decimal	**create_matrix_x(int x);
void		fill_matrix_x(t_decimal **array, int sz);
int			size_matrix(t_decimal **array);
void		test(t_rt *rt);

void	test2(t_rt *rt);
void	tick_environment(t_proj *proj, t_tuple *gravity, t_tuple *wind, t_rt *rt);

#endif 

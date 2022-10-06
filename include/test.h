/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:02:04 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/06 15:33:03 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#define TEST_H 

typedef struct	s_proj
{
	t_tuple	position;
	t_tuple	velocity;
}	t_proj;

void		test(t_rt *rt);
void		test2(t_rt *rt);
t_proj		tick_environment(t_proj proj, t_tuple gravity, t_tuple wind);
void		test3(t_rt *rt);


#endif 

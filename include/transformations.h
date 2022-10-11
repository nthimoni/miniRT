/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:48:18 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/10 22:51:16 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H 

# include "miniRT.h"

void	trans_mat_4(t_u m[4][4], t_u x, t_u y, t_u z);
void	scale_mat_4(t_u m[4][4], t_u x, t_u y, t_u z);
void	rot_x_mat_4(t_u m[4][4], t_u angle);
void	rot_y_mat_4(t_u m[4][4], t_u angle);
void	rot_z_mat_4(t_u m[4][4], t_u angle);
void	shearing_mat_4(t_u m[4][4], t_u shearing[6]);
void	mult_tuple_mat_4(t_tuple *new, t_u m[4][4], t_tuple t);


#endif 

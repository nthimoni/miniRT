/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:13:31 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/12 13:10:07 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H 

# include "miniRT.h"

void	create_ray(t_ray *new, t_tuple p, t_tuple v);
void	position(t_tuple *new, t_ray r, t_tuple p);
void	intersection(t_rt *rt, t_intersect inter[W_W][W_H]);
void	create_rays(t_rt *rt, t_intersect inter[W_W][W_H]);
void	pixel_raster_to_space(t_intersect *i, int x, int y, t_rt *rt);
void	init_pixel(t_rt *rt, t_intersect inter[W_W][W_H]);
void	init_rays(t_intersect inter[W_W][W_H]);
void	init_inter(t_rt *rt, t_intersect inter[W_W][W_H]);
void	world_to_camera(t_rt *rt);


#endif 

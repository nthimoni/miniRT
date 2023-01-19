/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:46:19 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/19 04:09:11 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H 

# include "data_struct.h"

typedef struct s_surface
{
	t_tuple	normal;
	t_tuple	pos;
	t_rt	*rt;
}	t_surface;

int		lighting(t_rt *rt, t_intersect *inter);
int		is_shadowed(t_rt *rt, t_tuple pos, t_tuple light_v, t_intersect *inter);
int		sub_synthese(int obj_color, int light_color, double ratio_light);
void	inc_color(int *color, int r, int g, int b);
int		set_diffuse(t_surface *sfc, t_tuple *light_v, t_obj *light);
int		set_specular(t_surface *sfc, t_tuple *light_v, t_rt *rt, t_obj *light);
void	define_uv(t_intersect *inter, t_tuple *pos);

#endif 

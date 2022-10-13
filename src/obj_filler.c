/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:48:27 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/13 23:19:08 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parsing.h"

int fill_light(t_obj *tmp, t_rt *rt, char **sp)
{
	float ratio;

	if (tmp->type == AMBIANT && ft_atof(sp[1], &ratio))
		return (1);
	if (tmp->type == LIGHT && ft_atof(sp[2], &ratio))
		return (1);
	tmp->ratio = (double)ratio;
}
int fill_cam(t_obj *tmp, t_rt *rt, char **sp)
{
}
int fill_plan(t_obj *tmp, t_rt *rt, char **sp)
{
}
int fill_sphere(t_obj *tmp, t_rt *rt, char **sp)
{
}
int fill_cylindre(t_obj *tmp, t_rt *rt, char **sp)
{
}

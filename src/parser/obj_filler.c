/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:48:27 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/19 14:41:03 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "exit_rt.h"
#include "data_struct.h"
#include "error.h"

static int	fill_light_properties(t_rt *rt, char **sp, t_obj *tmp)
{
	if (tmp->type == LIGHT)
		if (get_pos(sp[1], &tmp->o))
			return (1);
	if (tmp->type == LIGHT)
		sp++;
	if (get_ratio(sp[1], &tmp->ratio))
		return (1);
	if (get_color(sp[2], &tmp->color, tmp, rt))
		return (1);
	return (0);
}

int	fill_light(t_obj *tmp, t_rt *rt, char **sp)
{
	t_list	*new;

	if (fill_light_properties(rt, sp, tmp))
		return (free(tmp), 1);
	if (tmp->type == AMBIANT)
	{
		if (rt->scn.amb.is_init)
			return (free(tmp), 1);
		rt->scn.amb = *tmp;
		free(tmp);
		rt->scn.amb.is_init = 1;
	}
	else
	{
		new = ft_lstnew(tmp);
		if (!new)
		{
			free(tmp);
			free_split(sp);
			exit_parsing(rt, BAD_ALLOC_MSG, BAD_ALLOC);
		}
		ft_lstadd_back(&rt->scn.light, new);
	}
	return (0);
}

int	fill_cam(t_obj *tmp, t_rt *rt, char **sp)
{
	float	buf;

	if (rt->scn.cam.is_init)
		return (free(tmp), 1);
	if (get_pos(sp[1], &tmp->o))
		return (free(tmp), 1);
	if (get_ori(sp[2], &tmp->d))
		return (free(tmp), 1);
	if (ft_atof(sp[3], &buf) || buf < 0.f || buf > 180.f)
		return (free(tmp), 1);
	tmp->fov = buf;
	rt->scn.cam = *tmp;
	free(tmp);
	rt->scn.cam.is_init = 1;
	return (0);
}

int	fill_plan(t_obj *tmp, t_rt *rt, char **sp)
{
	t_list	*new;

	if (get_pos(sp[1], &tmp->o))
		return (free(tmp), 1);
	if (get_ori(sp[2], &tmp->d))
		return (free(tmp), 1);
	if (get_color(sp[3], &tmp->color, tmp, rt))
		return (free(tmp), 1);
	new = ft_lstnew(tmp);
	if (!new)
	{
		free(tmp);
		free_split(sp);
		exit_parsing(rt, BAD_ALLOC_MSG, BAD_ALLOC);
	}
	ft_lstadd_back(&rt->scn.objs, new);
	return (0);
}

int	fill_sphere(t_obj *tmp, t_rt *rt, char **sp)
{
	float	buf;
	t_list	*new;

	if (get_pos(sp[1], &tmp->o))
		return (free(tmp), 1);
	if (ft_atof(sp[2], &buf) || buf <= 0)
		return (free(tmp), 1);
	tmp->diam = buf;
	if (get_color(sp[3], &tmp->color, tmp, rt))
		return (free(tmp), 1);
	new = ft_lstnew(tmp);
	if (!new)
	{
		free(tmp);
		free_split(sp);
		exit_parsing(rt, BAD_ALLOC_MSG, BAD_ALLOC);
	}
	ft_lstadd_back(&rt->scn.objs, new);
	return (0);
}

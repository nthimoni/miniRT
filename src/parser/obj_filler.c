/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:48:27 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/17 18:31:36 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parsing.h"
#include "exit_rt.h"
#include "data_struct.h"
#include "error.h"
#include <stdio.h>

int fill_light(t_obj *tmp, t_rt *rt, char **sp)
{
	t_list	*new;

	if (tmp->type == LIGHT)
		if (get_pos(sp[1], &tmp->o))
			return (1);
	if (tmp->type == LIGHT)
		sp++;
	if (get_ratio(sp[1], &tmp->ratio))
		return (1);
	if (get_color(sp[2], &tmp->color, tmp, rt))
		return (1);
	if (tmp->type == AMBIANT)
	{
		rt->scn.amb = *tmp;
		free(tmp);
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

int fill_cam(t_obj *tmp, t_rt *rt, char **sp)
{
	float	buf;
	if (get_pos(sp[1], &tmp->o))
		return (1);
	if (get_ori(sp[2], &tmp->d))
		return (1);
	if (ft_atof(sp[3], &buf) || buf < 0.f || buf > 180.f)
		return (1);
	tmp->FOV = buf;
	rt->scn.cam = *tmp;
	free(tmp);
	return (0);
}
int fill_plan(t_obj *tmp, t_rt *rt, char **sp)
{
	t_list	*new;

	if (get_pos(sp[1], &tmp->o))
		return (1);
	if (get_ori(sp[2], &tmp->d))
		return (1);
	if (get_color(sp[3], &tmp->color, tmp, rt))
		return (1);
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

int fill_sphere(t_obj *tmp, t_rt *rt, char **sp)
{
	float	buf;
	t_list	*new;

	if (get_pos(sp[1], &tmp->o))
		return (1);
	if (ft_atof(sp[2], &buf))
		return (1);
	tmp->diam = buf;
	if (get_color(sp[3], &tmp->color, tmp, rt))
		return (1);
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

int fill_cylindre(t_obj *tmp, t_rt *rt, char **sp)
{
	float	buf;
	t_list	*new;

	if (get_pos(sp[1], &tmp->o))
		return (1);
	if (get_ori(sp[2], &tmp->d))
		return (1);
	if (ft_atof(sp[3], &buf))
		return (1);
	tmp->diam = buf;
	if (ft_atof(sp[4], &buf))
		return (1);
	tmp->height = buf;
	if (get_color(sp[5], &tmp->color, tmp, rt))
		return (1);
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

int fill_cone(t_obj *tmp, t_rt *rt, char **sp)
{
	float	buf;
	t_list	*new;

	if (get_pos(sp[1], &tmp->o))
		return (1);
	if (get_ori(sp[2], &tmp->d))
		return (1);
	if (ft_atof(sp[3], &buf))
		return (1);
	tmp->diam = buf;
	if (ft_atof(sp[4], &buf))
		return (1);
	tmp->height = buf;
	if (get_color(sp[5], &tmp->color, tmp, rt))
		return (1);
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

int fill_aa(t_obj *tmp, t_rt *rt, char **sp)
{
	float	buf;

	free(tmp);
	rt->aa.anti_aliasing = TRUE;
	if (ft_atof(sp[1], &buf))
		return (1);
	rt->aa.n = (unsigned int)buf;
	printf("AA.n = %d\n", rt->aa.n);
	return (0);
}

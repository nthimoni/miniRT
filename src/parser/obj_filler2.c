/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_filler2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:07:32 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/19 14:38:42 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"
#include "exit_rt.h"
#include "data_struct.h"

int	fill_cylindre(t_obj *tmp, t_rt *rt, char **sp)
{
	float	buf;
	t_list	*new;

	if (get_pos(sp[1], &tmp->o))
		return (free(tmp), 1);
	if (get_ori(sp[2], &tmp->d))
		return (free(tmp), 1);
	if (ft_atof(sp[3], &buf) || buf <= 0)
		return (free(tmp), 1);
	tmp->diam = buf;
	if (ft_atof(sp[4], &buf) || buf <= 0)
		return (free(tmp), 1);
	tmp->height = buf;
	if (get_color(sp[5], &tmp->color, tmp, rt))
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

int	fill_cone(t_obj *tmp, t_rt *rt, char **sp)
{
	float	buf;
	t_list	*new;

	if (get_pos(sp[1], &tmp->o))
		return (free(tmp), 1);
	if (get_ori(sp[2], &tmp->d))
		return (free(tmp), 1);
	if (ft_atof(sp[3], &buf) || buf <= 0)
		return (free(tmp), 1);
	tmp->diam = buf;
	if (ft_atof(sp[4], &buf) || buf <= 0)
		return (free(tmp), 1);
	tmp->height = buf;
	if (get_color(sp[5], &tmp->color, tmp, rt))
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

int	fill_aa(t_obj *tmp, t_rt *rt, char **sp)
{
	float	buf;

	free(tmp);
	if (rt->aa.anti_aliasing == TRUE)
		return (1);
	rt->aa.anti_aliasing = TRUE;
	if (!only_nb(sp[1]) || ft_atof(sp[1], &buf) || buf < 2)
		return (1);
	rt->aa.n = (unsigned int)buf;
	ft_printf("Anti-aliasing : %d\n", rt->aa.n);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:07:26 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/19 04:32:34 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "color.h"
#include "mlx.h"

int	get_color(char *s, int *color, t_obj *tmp, t_rt *rt)
{
	char	**sp;

	if (define_bump(rt, s, tmp))
		return (1);
	if (tmp->text == TEXTURE)
		return (0);
	if (ft_strncmp(s, "checker", 8) == 0)
		return (tmp->text = CHECKER, 0);
	sp = ft_split(s, ',');
	if (!sp)
		return (0);
	if (ft_strslen(sp) != 3)
		return (free_split(sp), 1);
	if (ft_strlen(sp[0]) > 3 || ft_strlen(sp[1]) > 3 || ft_strlen(sp[2]) > 3)
		return (free_split(sp), 1);
	if (!only_nb(sp[0]) || !only_nb(sp[1]) || !only_nb(sp[2]))
		return (free_split(sp), 1);
	if (parse_rgb(sp, color))
		return (1);
	return (tmp->text = COLOR, 0);
}

int	get_pos(char *s, t_tuple *pos)
{
	float	tmp;
	char	**sp;

	sp = ft_split(s, ',');
	if (ft_strslen(sp) != 3)
		return (free_split(sp), 1);
	if (ft_atof(sp[0], &tmp))
		return (free_split(sp), 1);
	pos->x = tmp;
	if (ft_atof(sp[1], &tmp))
		return (free_split(sp), 1);
	pos->y = tmp;
	if (ft_atof(sp[2], &tmp))
		return (free_split(sp), 1);
	free_split(sp);
	pos->z = tmp;
	pos->w = 1;
	return (0);
}

int	get_ratio(char *s, double *ratio)
{
	float	tmp;

	if (ft_atof(s, &tmp) || tmp > 1 || tmp < 0)
		return (1);
	*ratio = tmp;
	return (0);
}

int	get_ori(char *s, t_tuple *ori)
{
	if (get_pos(s, ori))
		return (1);
	ori->w = 0;
	if (ori->x > 1 || ori->x < -1)
		return (1);
	if (ori->y > 1 || ori->y < -1)
		return (1);
	if (ori->z > 1 || ori->z < -1)
		return (1);
	if (ori->x == 0 && ori->y == 0 && ori->z == 0)
		return (1);
	return (0);
}

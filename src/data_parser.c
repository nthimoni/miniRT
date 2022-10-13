/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:07:26 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/13 23:19:05 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parsing.h"

int	get_color(char *s, int *color)
{
	return (0);
}

int get_pos(char *s, t_tuple *pos)
{
	float	tmp;
	char	**sp;

	sp = ft_split(s, '.');
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

int get_ratio(char *s, double *ratio)
{
	float	tmp;

	if (ft_atof(s, &tmp) || tmp > 1 || tmp < 0)
		return (1);
	*ratio = tmp;
	return (0);
}

int	get_ori(char *s, t_tuple *ori)
{
	return (0);
}

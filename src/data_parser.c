/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:07:26 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/14 12:09:48 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parsing.h"

static int	only_nb(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	get_color(char *s, int *color)
{
	char	**sp;
	int		r;
	int		g;
	int		b;

	sp = ft_split(s, ',');
	if (ft_strslen(sp) != 3)
		return (free_split(sp), 1);
	if (ft_strlen(sp[0]) > 3 || ft_strlen(sp[1]) > 3 || ft_strlen(sp[2]) > 3)
		return (free_split(sp), 1);
	if (!only_nb(sp[0]) || !only_nb(sp[1]) || !only_nb(sp[2]))
		return (free_split(sp), 1);
	r = ft_atoi(sp[0]);
	g = ft_atoi(sp[1]);
	b = ft_atoi(sp[2]);
	free_split(sp);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	*color = create_trgb(0, r, g, b);
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
	if (get_pos(s, ori))
		return (1);
	if (ori->x > 1 || ori->x < -1)
		return (1);
	if (ori->y > 1 || ori->y < -1)
		return (1);
	if (ori->z > 1 || ori->z < -1)
		return (1);
	return (0);
}

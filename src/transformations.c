/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:48:24 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/10 23:21:35 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformations.h"
#include <math.h>
#include "miniRT.h"

void	trans_mat_4(t_u m[4][4], t_u x, t_u y, t_u z)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (i == j)
				m[i][j] = 1;
			else
				m[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	m[0][3] = x;
	m[1][3] = y;
	m[2][3] = z;
}

void	scale_mat_4(t_u m[4][4], t_u x, t_u y, t_u z)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	m[0][0] = x;
	m[1][1] = y;
	m[2][2] = z;
	m[3][3] = 1;
}

void	rot_x_mat_4(t_u m[4][4], t_u angle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	m[0][0] = 1;
	m[1][1] = cos(angle);
	m[1][2] = -sin(angle);
	m[2][1] = sin(angle);
	m[2][2] = cos(angle);
	m[3][3] = 1;
}

void	rot_y_mat_4(t_u m[4][4], t_u angle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	m[0][0] = cos(angle);
	m[0][2] = sin(angle);
	m[1][1] = 1;
	m[2][0] = -sin(angle);
	m[2][2] = cos(angle);
	m[3][3] = 1;
}

void	rot_z_mat_4(t_u m[4][4], t_u angle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	m[0][0] = cos(angle);
	m[0][1] = -sin(angle);
	m[1][0] = sin(angle);
	m[1][1] = cos(angle);
	m[2][2] = 1;
	m[3][3] = 1;
}

void	shearing_mat_4(t_u m[4][4], t_u shearing[6])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (i == j)
				m[i][j] = 1;
			else
				m[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	m[0][1] = shearing[0];
	m[0][2] = shearing[1];
	m[1][0] = shearing[2];
	m[1][2] = shearing[3];
	m[2][0] = shearing[4];
	m[2][1] = shearing[5];
}

void	mult_tuple_mat_4(t_tuple *new, t_u m[4][4], t_tuple t)
{
	new->x = t.x * m[0][0] + t.y * m[0][1] + t.z * m[0][2] + t.w *m[0][3];
	new->y = t.x * m[1][0] + t.y * m[1][1] + t.z * m[1][2] + t.w *m[1][3];
	new->z = t.x * m[2][0] + t.y * m[2][1] + t.z * m[2][2] + t.w *m[2][3];
	new->w = t.x * m[3][0] + t.y * m[3][1] + t.z * m[3][2] + t.w *m[3][3];
}

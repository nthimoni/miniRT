/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:48:24 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/14 13:32:50 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformations.h"

void	trans_matrix_4(t_u m[4][4], t_u x, t_u y, t_u z)
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

void	scale_matrix_4(t_u m[4][4], t_u x, t_u y, t_u z)
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

void	rot_x_matrix_4(t_u m[4][4], t_u angle)
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

void	rot_y_matrix_4(t_u m[4][4], t_u angle)
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

void	rot_z_matrix_4(t_u m[4][4], t_u angle)
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

void	shearing_matrix_4(t_u m[4][4], t_u shearing[6])
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

void	mult_tuple_matrix_4(t_tuple *new, t_u m[4][4], t_tuple t)
{
	new->x = t.x * m[0][0] + t.y * m[0][1] + t.z * m[0][2] + t.w *m[0][3];
	if (new->x > -EPS && new->x < EPS)
		new->x = 0;
	new->y = t.x * m[1][0] + t.y * m[1][1] + t.z * m[1][2] + t.w *m[1][3];
	if (new->y > -EPS && new->y < EPS)
		new->y = 0;
	new->z = t.x * m[2][0] + t.y * m[2][1] + t.z * m[2][2] + t.w *m[2][3];
	if (new->z > -EPS && new->z < EPS)
		new->z = 0;
	new->w = t.x * m[3][0] + t.y * m[3][1] + t.z * m[3][2] + t.w *m[3][3];
	if (new->w > -EPS && new->w < EPS)
		new->w = 0;
}

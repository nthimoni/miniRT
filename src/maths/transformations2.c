/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:39:39 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 15:52:32 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformations.h"

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
	new->x = t.x * m[0][0] + t.y * m[0][1] + t.z * m[0][2] + t.w * m[0][3];
	if (new->x > -EPS && new->x < EPS)
		new->x = 0;
	new->y = t.x * m[1][0] + t.y * m[1][1] + t.z * m[1][2] + t.w * m[1][3];
	if (new->y > -EPS && new->y < EPS)
		new->y = 0;
	new->z = t.x * m[2][0] + t.y * m[2][1] + t.z * m[2][2] + t.w * m[2][3];
	if (new->z > -EPS && new->z < EPS)
		new->z = 0;
	new->w = t.x * m[3][0] + t.y * m[3][1] + t.z * m[3][2] + t.w * m[3][3];
	if (new->w > -EPS && new->w < EPS)
		new->w = 0;
}

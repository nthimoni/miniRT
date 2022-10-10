/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:48:24 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/10 20:53:17 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformations.h"

void	trans_mat_4(t_decimal m[4][4], t_decimal x, t_decimal y, t_decimal z)
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

void	trans_mat_4(t_decimal m[4][4], t_decimal x, t_decimal y, t_decimal z)
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

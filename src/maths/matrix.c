/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:04:54 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 15:55:06 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_u	**create_matrix_x(int x)
{
	t_u	**array;
	int	i;

	array = malloc(sizeof(t_u *) * (x + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < x)
	{
		array[i] = malloc(sizeof(t_u) * x);
		if (!array[i])
			return (NULL);
		ft_bzero(array[i], sizeof(t_u) * x);
		i++;
	}
	array[x] = NULL;
	return (array);
}

void	mult_matrix_4(t_u new[4][4], t_u m1[4][4], t_u m2[4][4])
{
	u_int8_t	a;
	u_int8_t	b;

	a = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			new[a][b] = m1[a][0] * m2[0][b] + m1[a][1] * m2[1][b]
				+ m1[a][2] * m2[2][b] + m1[a][3] * m2[3][b];
			clamp(&new[a][b]);
			b++;
		}
		a++;
	}
	return ;
}

void	mult_matrix_4bis(t_u (*new)[4][4], t_u m1[4][4], t_u m2[4][4])
{
	t_matex	i;

	ft_bzero(&i, sizeof(t_matex));
	while (i.a < 4)
	{
		while (i.b < 4)
		{
			while (i.c < 4)
			{
				*new[i.a][i.b] += m1[i.a][i.c++] * m2[i.d++][i.b];
				clamp(new[i.a][i.b]);
			}
			i.c = 0;
			i.d = 0;
			i.b++;
		}
		i.b = 0;
		i.a++;
	}
	return ;
}

void	identity_matrix_4(t_u new[4][4])
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (i == j)
				new[i][j] = 1;
			else
				new[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

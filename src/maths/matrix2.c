/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:50:19 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 14:52:23 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	transpose_matrix_4(t_u m[4][4], t_u new[4][4])
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			new[i][j] = m[j][i];
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

t_u	det_matrix_2(t_u m[2][2])
{
	t_u	ret;

	ret = m[0][0] * m[1][1] - m[0][1] * m[1][0];
	clamp(&ret);
	return (ret);
}

void	sub_matrix_4(t_u m[4][4], int a, int b, t_u new[3][3])
{
	t_matex	i;

	i.a = a;
	i.b = b;
	i.c = 0;
	i.d = 0;
	while (i.c < i.a)
	{
		while (i.d < i.b)
		{
			new[i.c][i.d] = m[i.c][i.d];
			i.d++;
		}
		i.d++;
		while (i.d < 4)
		{
			new[i.c][i.d - 1] = m[i.c][i.d];
			i.d++;
		}
		i.c++;
		i.d = 0;
	}
	i.c++;
	sub_matrix_4_1(m, new, i);
	return ;
}

void	sub_matrix_4_1(t_u m[4][4], t_u new[3][3], t_matex i)
{
	while (i.c < 4)
	{
		while (i.d < i.b)
		{
			new[i.c - 1][i.d] = m[i.c][i.d];
			i.d++;
		}
		i.d++;
		while (i.d < 4)
		{
			new[i.c - 1][i.d - 1] = m[i.c][i.d];
			i.d++;
		}
		i.c++;
		i.d = 0;
	}
	return ;
}

void	sub_matrix_3(t_u m[3][3], int a, int b, t_u new[2][2])
{
	t_matex	i;

	i.a = a;
	i.b = b;
	i.c = 0;
	i.d = 0;
	while (i.c < i.a)
	{
		while (i.d < i.b)
		{
			new[i.c][i.d] = m[i.c][i.d];
			i.d++;
		}
		i.d++;
		while (i.d < 3)
		{
			new[i.c][i.d - 1] = m[i.c][i.d];
			i.d++;
		}
		i.c++;
		i.d = 0;
	}
	i.c++;
	sub_matrix_3_1(m, new, i);
	return ;
}

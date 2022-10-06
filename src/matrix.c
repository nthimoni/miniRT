/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:04:54 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/06 17:38:28 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "miniRT.h"

t_decimal	**create_matrix_x(int x)
{
	t_decimal	**array;
	int			i;

	array = malloc(sizeof(t_decimal *) * (x + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < x)
	{
		array[i] = malloc(sizeof(t_decimal) * x);
		if (!array[i])
			return (NULL);
		ft_bzero(array[i], sizeof(t_decimal) * x);
		i++;
	}
	array[x] = NULL;
	return (array);
}

void	fill_matrix_x(t_decimal *[4]array, int sz, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("Fill matrix %s of size %dx%d :\n", str, sz, sz);
	while (i < sz)
	{
		while (j < sz)
		{
			printf("[%d][%d] :", i, j);
			scanf("%lf",&array[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

t_decimal	**mult_matrix_x(int x, t_decimal *[4]new, t_decimal *[4]m1, t_decimal *[4]m2)
{
	t_matrix_index	i;

	ft_bzero(&i, sizeof(t_matrix_index));
	while (i.a < x)
	{
		while (i.b < x)
		{
			while (i.c < x)
				new[i.a][i.b] += m1[i.a][i.c++] * m2[i.d++][i.b];
			i.c = 0;
			i.d = 0;
			i.b++;
		}
		i.b = 0;
		i.a++;
	}
	return ;
}

void	identity_matrix(t_decimal *[4]new)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (i == j)
				new[i][j] = 1;
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

t_decimal	**transpose_matrix(t_decimal *[4]m, int size, t_decimal *[4]new)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			new[i][j] = m[j][i];
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

t_decimal	det_matrix_2(t_decimal *[4]m)
{
	return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}

void	sub_matrix(t_decimal *[4]m, int sz, int a, int b, t_decimal *[4]new)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < a)
	{
		while (j < b)
		{
			new[i][j] = m[i][j];
			j++;
		}
		j++;
		while (j < sz)
		{
			new[i][j - 1] = m[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	i++;
	while (i < sz)
	{
		while (j < b)
		{
			new[i - 1][j] = m[i][j];
			j++;
		}
		j++;
		while (j < sz)
		{
			new[i - 1][j - 1] = m[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return ;
}

void	matrix_ex1(t_decimal *[4]new)
{
	new[0][0] = 1;
	new[0][1] = 2;
	new[0][2] = 3;
	new[0][3] = 4;
	new[1][0] = 5;
	new[1][1] = 6;
	new[1][2] = 7;
	new[1][3] = 8;
	new[2][0] = 9;
	new[2][1] = 8;
	new[2][2] = 7;
	new[2][3] = 6;
	new[3][0] = 5;
	new[3][1] = 4;
	new[3][2] = 3;
	new[3][3] = 2;
	return ;
}

void	matrix_ex2(t_decimal *[4]new)
{
	new[0][0] = -2;
	new[0][1] = 1;
	new[0][2] = 2;
	new[0][3] = 3;
	new[1][0] = 3;
	new[1][1] = 2;
	new[1][2] = 1;
	new[1][3] = -1;
	new[2][0] = 4;
	new[2][1] = 3;
	new[2][2] = 6;
	new[2][3] = 5;
	new[3][0] = 1;
	new[3][1] = 2;
	new[3][2] = 7;
	new[3][3] = 8;
	return ;
}

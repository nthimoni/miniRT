/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:04:54 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/09 23:20:12 by bek              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "miniRT.h"
#include "print.h"

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

void	fill_matrix_x(t_decimal array[4][4], int sz, char *str)
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

void	mult_matrix_4(t_decimal new[4][4], t_decimal m1[4][4], t_decimal m2[4][4])
{
	t_matex	i;

	ft_bzero(&i, sizeof(t_matex));
	while (i.a < 4)
	{
		while (i.b < 4)
		{
			while (i.c < 4)
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

void	identity_matrix(t_decimal new[4][4])
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
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

void	transpose_matrix_4(t_decimal m[4][4], t_decimal new[4][4])
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

t_decimal	det_matrix_2(t_decimal m[2][2])
{
	return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}

void	sub_matrix_4(t_decimal m[4][4], int a, int b, t_decimal new[3][3])
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

void	sub_matrix_4_1(t_decimal m[4][4], t_decimal new[3][3], t_matex i)
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

void	sub_matrix_3(t_decimal m[3][3], int a, int b, t_decimal new[2][2])
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
	sub_matrix_3_1(m, new, i);
	return ;
}

void	sub_matrix_3_1(t_decimal m[3][3], t_decimal new[2][2], t_matex i)
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

t_decimal	minor_matrix_3(t_decimal m[3][3], int a, int b)
{
	t_decimal	new[2][2];
	t_decimal	ret;

	ret = 0;
	ft_bzero(&new, sizeof(t_decimal[2][2]));
	sub_matrix_3(m, a, b, new);
	print_matrix_2(new, "new = m sub(0, 0)");
	printf("a = %d b = %d\n", a, b);
	ret = det_matrix_2(new);
	printf("ret = %lf\n", ret);
	return (ret);
}

void	matrix_ex1(t_decimal new[4][4])
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

void	matrix_ex2(t_decimal new[4][4])
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

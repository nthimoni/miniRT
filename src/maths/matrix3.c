/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:50:43 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 14:52:23 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	sub_matrix_3_1(t_u m[3][3], t_u new[2][2], t_matex i)
{
	while (i.c < 3)
	{
		while (i.d < i.b)
		{
			new[i.c - 1][i.d] = m[i.c][i.d];
			i.d++;
		}
		i.d++;
		while (i.d < 3)
		{
			new[i.c - 1][i.d - 1] = m[i.c][i.d];
			i.d++;
		}
		i.c++;
		i.d = 0;
	}
	return ;
}

t_u	minor_matrix_3(t_u m[3][3], int a, int b)
{
	t_u	new[2][2];
	t_u	ret;

	ret = 0;
	ft_bzero(&new, sizeof(t_u[2][2]));
	sub_matrix_3(m, a, b, new);
	ret = det_matrix_2(new);
	return (ret);
}

t_u	cofactor_matrix_3(t_u m[3][3], int a, int b)
{
	t_u	new[2][2];
	t_u	ret;

	ret = 0;
	ft_bzero(&new, sizeof(t_u[2][2]));
	sub_matrix_3(m, a, b, new);
	ret = det_matrix_2(new);
	if ((a + b) % 2 && ret)
		return (-ret);
	return (ret);
}

t_u	cofactor_matrix_4(t_u m[4][4], int a, int b)
{
	t_u	new[3][3];
	t_u	ret;

	ret = 0;
	ft_bzero(&new, sizeof(t_u[2][2]));
	sub_matrix_4(m, a, b, new);
	ret = det_matrix_3(new);
	if ((a + b) % 2 && ret)
		return (-ret);
	return (ret);
}

t_u	det_matrix_3(t_u m[3][3])
{
	t_u	ret;

	ret = m[0][0] * cofactor_matrix_3(m, 0, 0)
		+ m[0][1] * cofactor_matrix_3(m, 0, 1)
		+ m[0][2] * cofactor_matrix_3(m, 0, 2);
	return (ret);
}

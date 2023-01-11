/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:51:04 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 15:53:37 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_u	det_matrix_4(t_u m[4][4])
{
	t_u	ret;
	t_u	new_0[3][3];
	t_u	new_1[3][3];
	t_u	new_2[3][3];
	t_u	new_3[3][3];

	sub_matrix_4(m, 0, 0, new_0);
	sub_matrix_4(m, 0, 1, new_1);
	sub_matrix_4(m, 0, 2, new_2);
	sub_matrix_4(m, 0, 3, new_3);
	ret = m[0][0] * det_matrix_3(new_0) - m[0][1] * det_matrix_3(new_1)
		+ m[0][2] * det_matrix_3(new_2) - m[0][3] * det_matrix_3(new_3);
	clamp(&ret);
	return (ret);
}

t_bool	matrix_4_is_invertible(t_u m[4][4])
{
	if (det_matrix_4(m))
		return (TRUE);
	return (FALSE);
}

void	invert_matrix_4(t_u m[4][4], t_u new[4][4])
{
	int	i;
	int	j;
	t_u	det;

	i = 0;
	j = 0;
	det = det_matrix_4(m);
	if (!matrix_4_is_invertible(m))
		return ;
	while (i < 4)
	{
		while (j < 4)
		{
			new[j][i] = cofactor_matrix_4(m, i, j) / det;
			clamp(&new[j][i]);
			j++;
		}
		i++;
		j = 0;
	}
}

void	clamp(t_u *x)
{
	if (*x > -EPS && *x < EPS)
		*x = +0.0;
	if (*x > 1 - EPS && *x < 1 + EPS)
		*x = 1;
	if (*x > -1 - EPS && *x < -1 + EPS)
		*x = -1;
}

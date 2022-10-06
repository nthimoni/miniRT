/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.62.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:66:33 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/06 13:55:33 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_tuple(t_tuple *t, char *str)
{
	printf("%s :\n| %6.1lf |\n| %6.1lf |\n| %6.1lf |\n| %6.1lf |\n",
			str, t->x, t->y, t->z, t->w);
}

void	print_matrix4(t_decimal **m, char *s)
{
	printf("Matrix %s :\n| %6.1lf %6.1lf %6.1lf %6.1lf |\n| %6.1lf %6.1lf %6.1lf %6.1lf |\n| %6.1lf %6.1lf %6.1lf %6.1lf |\n| %6.1lf %6.1lf %6.1lf %6.1lf |\n", s,
			m[0][0], m[0][1], m[0][2], m[0][3],
			m[1][0], m[1][1], m[1][2], m[1][3],
			m[2][0], m[2][1], m[2][2], m[2][3],
			m[3][0], m[3][1], m[3][2], m[3][3]);
}

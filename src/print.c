/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.62.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06.22:66:33 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/14 14:34:29 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_tuple(t_tuple *t, char *str)
{
	printf("%s :\n| %6.2lf |\n| %6.2lf |\n| %6.2lf |\n| %6.2lf |\n",
			str, t->x, t->y, t->z, t->w);
}

void	print_matrix_4(t_u m[4][4], char *s)
{
	printf("Matrix %s :\n| %6.2lf %6.2lf %6.2lf %6.2lf |\n| %6.2lf %6.2lf %6.2lf %6.2lf |\n| %6.2lf %6.2lf %6.2lf %6.2lf |\n| %6.2lf %6.2lf %6.2lf %6.2lf |\n", s,
			m[0][0], m[0][1], m[0][2], m[0][3],
			m[1][0], m[1][1], m[1][2], m[1][3],
			m[2][0], m[2][1], m[2][2], m[2][3],
			m[3][0], m[3][1], m[3][2], m[3][3]);
}

void	print_matrix_3(t_u m[3][3], char *s)
{
	printf("Matrix %s :\n| %6.2lf %6.2lf %6.2lf |\n",
			s, m[0][0], m[0][1], m[0][2]);
	printf("| %6.2lf %6.2lf %6.2lf |\n", m[1][0], m[1][1], m[1][2]);
	printf("| %6.2lf %6.2lf %6.2lf |\n", m[2][0], m[2][1], m[2][2]);
}

void	print_matrix_2(t_u m[2][2], char *s)
{
	printf("Matrix %s :\n| %6.2lf %6.2lf |\n",
			s, m[0][0], m[0][1]);
	printf("| %6.2lf %6.2lf |\n", m[1][0], m[1][1]);
}

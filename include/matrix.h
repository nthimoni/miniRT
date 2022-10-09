/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:05:46 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/09 23:02:08 by bek              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
#define MATRIX_H 

# include "miniRT.h"

typedef struct	s_matrix_index
{
	int	a;
	int	b;
	int	c;
	int	d;
}	t_matex;

t_decimal	**create_matrix_x(int x);
void		fill_matrix_x(t_decimal array[4][4], int sz, char *str);
void		mult_matrix_4(t_decimal new[4][4], t_decimal m1[4][4], t_decimal m2[4][4]);
void		identity_matrix(t_decimal new[4][4]);
void		transpose_matrix_4(t_decimal m[4][4], t_decimal new[4][4]);
t_decimal	det_matrix_2(t_decimal m[2][2]);
void		sub_matrix_4(t_decimal m[4][4], int a, int b, t_decimal new[3][3]);
void		sub_matrix_4_1(t_decimal m[4][4], t_decimal new[3][3], t_matex i);
void		sub_matrix_3(t_decimal m[3][3], int a, int b, t_decimal new[2][2]);
void		sub_matrix_3_1(t_decimal m[3][3], t_decimal new[2][2], t_matex i);
t_decimal	minor_matrix_3(t_decimal m[3][3], int a, int b);
void		matrix_ex1(t_decimal new[4][4]);
void		matrix_ex2(t_decimal new[4][4]);

#endif 

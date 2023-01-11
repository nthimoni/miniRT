/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:05:46 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 19:19:59 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
#define MATRIX_H 

# include "data_struct.h"
# include "print.h"

typedef struct	s_matrix_index
{
	int	a;
	int	b;
	int	c;
	int	d;
}	t_matex;

t_u		**create_matrix_x(int x);
void	fill_matrix_x(t_u array[4][4], int sz, char *str);
void	mult_matrix_4(t_u new[4][4], t_u m1[4][4], t_u m2[4][4]);
void	mult_matrix_4bis(t_u (*new)[4][4], t_u m1[4][4], t_u m2[4][4]);
void	identity_matrix_4(t_u new[4][4]);
void	transpose_matrix_4(t_u m[4][4], t_u new[4][4]);
t_u		det_matrix_2(t_u m[2][2]);
void	sub_matrix_4(t_u m[4][4], int a, int b, t_u new[3][3]);
void	sub_matrix_4_1(t_u m[4][4], t_u new[3][3], t_matex i);
void	sub_matrix_3(t_u m[3][3], int a, int b, t_u new[2][2]);
void	sub_matrix_3_1(t_u m[3][3], t_u new[2][2], t_matex i);
t_u		minor_matrix_3(t_u m[3][3], int a, int b);
t_u		cofactor_matrix_3(t_u m[3][3], int a, int b);
t_u		cofactor_matrix_4(t_u m[4][4], int a, int b);
t_u		det_matrix_3(t_u m[3][3]);
t_u		det_matrix_4(t_u m[4][4]);
t_bool	matrix_4_is_invertible(t_u m[4][4]);
void	invert_matrix_4(t_u m[4][4], t_u new[4][4]);
void	matrix_ex1(t_u new[4][4]);
void	matrix_ex2(t_u new[4][4]);
void	matrix_ex3(t_u new[3][3]);
void	matrix_ex4(t_u new[4][4]);
t_u		max_u(t_u a, t_u b);
t_u		min_u(t_u a, t_u b);
void	clamp(t_u *x);
t_u		abs_u(t_u n);

#endif 

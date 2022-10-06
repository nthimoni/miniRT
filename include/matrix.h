/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:05:46 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/06 17:38:28 by rmorel           ###   ########.fr       */
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
}	t_matrix_index;

t_decimal	**create_matrix_x(int x);
void		fill_matrix_x(t_decimal *[4]array, int sz, char *str);
t_decimal	**mult_matrix_x(int x, t_decimal *[4]new, t_decimal *[4]m1, t_decimal *[4]m2);
void		identity_matrix(t_decimal *[4]new);
t_decimal	**transpose_matrix(t_decimal *[4]m, int size, t_decimal *[4]new);
t_decimal	det_matrix_2(t_decimal *[4]m);
void		sub_matrix(t_decimal *[4]m, int sz, int a, int b, t_decimal *[4]new);
void		matrix_ex1(t_decimal *[4]new);
void		matrix_ex2(t_decimal *[4]new);

#endif 

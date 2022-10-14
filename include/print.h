/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:36:56 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/14 13:28:32 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
#define PRINT_H 

# include "data_struct.h"
# include <stdio.h>

void	print_tuple(t_tuple *t, char *str);
void	print_matrix_4(t_u m[4][4], char *s);
void	print_matrix_3(t_u m[3][3], char *s);
void	print_matrix_2(t_u m[2][2], char *s);


#endif 

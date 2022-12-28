/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 03:00:54 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/15 20:15:12 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H 

# define CHECKER_WIDTH_P 4
# define CHECKER_HEIGHT_P 8

# define CHECKER_WIDTH_S 16
# define CHECKER_HEIGHT_S 32

# define CHECKER_COL_1 0x00000000
# define CHECKER_COL_2 0x00FFFFFF

# include "data_struct.h"

t_2dp sphere_pos_to_2d(t_tuple *pos, t_u radius);
t_2dp plan_pos_to_2d(t_tuple *pos);
int get_color_checker(t_2dp pos, t_intersect *inter);

#endif 

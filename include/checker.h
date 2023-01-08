/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 03:00:54 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/08 20:18:16 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H 

# define CHECKER_WIDTH_P 4
# define CHECKER_HEIGHT_P 8

# define CHECKER_WIDTH_S 6
# define CHECKER_HEIGHT_S 12

# define CHECKER_COL_1 0x00000000
# define CHECKER_COL_2 0x00FFFFFF

# include "data_struct.h"

t_2dp uv_sphere(t_tuple *pos);
t_2dp uv_plan(t_tuple *pos);
int get_color_checker(t_2dp pos, t_intersect *inter);

#endif 

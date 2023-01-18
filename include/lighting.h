/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:46:19 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/18 18:55:43 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H 

# include "data_struct.h"

int	lighting(t_rt *rt, t_intersect *inter);
int	isShadowed(t_rt *rt, t_tuple pos, t_tuple light_v, t_intersect *inter);

#endif 

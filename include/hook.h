/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:05:16 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/14 13:30:46 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
#define HOOK_H 

# include "data_struct.h"
# include "mlx.h"

int	red_cross(t_rt *rt);
int	key_hook(int keycode, t_rt *rt);

#endif 

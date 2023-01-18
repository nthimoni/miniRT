/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:04:34 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/18 18:55:29 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H 

# include "data_struct.h"
# include "mlx.h"

void	clear_image(t_rt *rt);
void	my_mlx_pixel_put(t_rt *rt, int x, int y, int color);
int		render_next_frame(t_rt *rt);

#endif 

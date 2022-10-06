/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:18:25 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/06 13:55:31 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define W_W 1920
# define W_H 1080

# include	"libft.h"
# include <math.h>
# include <stdio.h>
# include <mlx.h>

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_lgth;
	int		endian;
	int		x;
	int		y;
}	t_img;

typedef struct	s_rt
{
	t_list	*trash;
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_rt;

typedef double	t_decimal;

typedef struct	s_tuple
{
	t_decimal	x;
	t_decimal	y;
	t_decimal	z;
	t_decimal	w;
}	t_tuple;

//	colors.c

int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

//	hook.h

int	red_cross(t_rt *rt);

//	image.c

void	clear_image(t_rt *rt);
void	my_mlx_pixel_put(t_rt *rt, int x, int y, int color);
int		render_next_frame(t_rt *rt);

//	main.c

t_rt	*init_rt(void);

#endif 

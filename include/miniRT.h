/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:18:25 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/12 14:16:16 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define W_W 1920
# define W_H 1080

# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <mlx.h>

typedef double	t_u;

typedef struct	s_tuple
{
	t_u	x;
	t_u	y;
	t_u	z;
	t_u	w;
}	t_tuple;

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

#include "parsing.h"

typedef struct	s_rt
{
	t_list	*trash;
	void	*mlx;
	void	*win;
	t_img	*img;
	t_scene	scn;
}	t_rt;


typedef	enum	e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct	s_ray
{
	t_tuple	o;
	t_tuple	d;
}	t_ray;

typedef struct	s_intersect
{
	t_tuple	pixel;
	t_bool	intersect;
	t_ray	ray;
//	t_obj	*obj;
	t_tuple	i1;
	t_tuple	i2;
}	t_intersect;
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

//	init.c

t_rt	*init_rt(void);
int		key_hook(int keycode, t_rt *rt);

#endif 

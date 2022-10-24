/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:01:40 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/24 14:25:49 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H 

# include "libft.h"

# define W_W 1920
# define W_H 1080
# define EPS 0.000001
# define INF 1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583687

typedef double	t_u;

typedef struct	s_tuple
{
	t_u	x;
	t_u	y;
	t_u	z;
	t_u	w;
}	t_tuple;

typedef enum e_otype
{
	NONE = 0,
	AMBIANT,
	CAMERA,
	SPHERE,
	PLAN,
	CYLINDRE,
	LIGHT
}	t_otype;

typedef enum	e_space
{
	WORLD = 0,
	CAM,
	OBJ,
}	t_space;

typedef struct s_obj
{
	t_otype	type;
	t_tuple	o;
	t_tuple	d;
	double	diam;
	double	height;
	t_u		FOV;
	int		color;
	double	ratio;
	t_u		wtoo_m[4][4];
	t_u		otow_m[4][4];
}	t_obj;

typedef struct s_scene
{
	t_obj amb;
	t_obj	cam;
	t_list	*light;
	t_list	*objs;
}	t_scene;

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

typedef	enum	e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct	s_rt
{
	t_list	*trash;
	void	*mlx;
	void	*win;
	t_img	*img;
	t_u		wtoc_m[4][4];
	t_u		ctow_m[4][4];
	t_scene	scn;
	t_space	space;
	t_bool	debug;
}	t_rt;

typedef struct	s_ray
{
	t_tuple	o;
	t_tuple	d;
}	t_ray;

typedef struct	s_quadra
{
	t_u		disc;
	t_u		a;
	t_u		b;
	t_u		c;
	t_u		q;
}	t_quadra;

typedef struct	s_intersect
{
	int			x;
	int			y;
	t_tuple		pixel;
	t_ray		ray;
	t_u			t0;
	t_u			t1;
	t_u			t0_tmp;
	t_u			t1_tmp;
	t_quadra	q;
	t_obj		*obj;
}	t_intersect;

#endif 

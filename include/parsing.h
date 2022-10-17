/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:02 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/17 14:38:56 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H 

#include "miniRT.h"


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


typedef struct s_obj
{
	t_otype	type;
	t_tuple	o;
	t_tuple	d;
	double	diam;
	double	height;
	double	FOV;
	int		color;
	double	ratio;
}	t_obj;

typedef struct s_scene
{
	t_obj amb;
	t_obj	cam;
	t_list	*light;
	t_list	*objs;
}	t_scene;

void	void_parsing(char *file, t_scene *scene);
int 	ft_strslen(char **sp);
t_obj	*creat_obj(t_otype type);
int		ft_atof(char *str, float *val);
void	free_split(char **sp);
int	get_ori(char *s, t_tuple *ori);
int get_ratio(char *s, double *ratio);
int get_pos(char *s, t_tuple *pos);
int	get_color(char *s, int *color);
int isValidLiteral(char *str);

#endif 

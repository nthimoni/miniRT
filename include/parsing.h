/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:02 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/12 14:15:14 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H 

#include "libft.h"

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
	float	diam;
	float	height;
	int		FOV;
	int		color;
	float	ratio;
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

#endif 

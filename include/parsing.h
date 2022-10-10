/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:02 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/10 19:11:19 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H 

#include "miniRT.h"


typedef enum e_otype
{
	CAMERA,
	SPHERE,
	PLAN,
	CYLINDRE
}	t_otype;

typedef struct s_light
{
	int		color;
	float	ratio;
	t_tuple	postion;
}	t_light;

typedef struct s_obj
{
	t_otype	type;
	t_tuple	postion;
	t_tuple	orientation;
	float	diameter;
	float	height;
	int		FOV;
	int		color;
}	t_obj;

typedef struct s_scene
{
	t_light ambiant;
	t_obj	camera;
	t_list	*lights;
	t_list	*objs;
}	t_scene;

void	void_parsing(char *file, t_scene *scene);

#endif 

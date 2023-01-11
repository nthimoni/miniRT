/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:56:34 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/11 18:16:14 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_tuple(t_tuple *t, char *str)
{
	printf("%s :\n| %6.2lf |\n| %6.2lf |\n| %6.2lf |\n| %6.2lf |\n",
		str, t->x, t->y, t->z, t->w);
}

void	print_cone_test_tuple(t_tuple o, t_tuple d, t_tuple top, t_tuple t[2])
{
	printf("%-10s | %-10s | %-10s | %-10s |", "o", "d", "top", "t1");
	printf(" %-10s\n", "t2");
	printf("----------------------------------------------------------------\n");
	printf("%-10.2lf | %-10.2lf | %-10.2lf |", o.x, d.x, top.x);
	printf(" %-10.2lf | %-10.2lf\n", t[0].x, t[1].x);
	printf("%-10.2lf | %-10.2lf | %-10.2lf |", o.y, d.y, top.y);
	printf(" %-10.2lf | %-10.2lf\n", t[0].y, t[1].y);
	printf("%-10.2lf | %-10.2lf | %-10.2lf |", o.z, d.z, top.z);
	printf(" %-10.2lf | %-10.2lf\n", t[0].z, t[1].z);
	printf("%-10.2lf | %-10.2lf | %-10.2lf |", o.w, d.w, top.w);
	printf(" %-10.2lf | %-10.2lf\n", t[0].w, t[1].w);
}

void	print_matrix_4(t_u m[4][4], char *s)
{
	printf("Matrix %s :\n| %6.2lf %6.2lf %6.2lf %6.2lf |\n| ", s,
		m[0][0], m[0][1], m[0][2], m[0][3]);
	printf("%6.2lf %6.2lf %6.2lf %6.2lf |\n| ", m[1][0], m[1][1],
		m[1][2], m[1][3]);
	printf("%6.2lf %6.2lf %6.2lf %6.2lf |\n| ", m[2][0], m[2][1],
		m[2][2], m[2][3]);
	printf("%6.2lf %6.2lf %6.2lf %6.2lf |\n", m[3][0], m[3][1],
		m[3][2], m[3][3]);
}

void	print_obj(t_obj *obj)
{
	const char	*s[8] = {"NONE", "AMBIANT", "CAMERA", "SPHERE",
		"PLAN", "CYLINDRE", "CONE", "LIGHT"};

	printf("OBJ_TYPE = %s\n", s[obj->type]);
	print_tuple(&obj->o, "Origin");
	print_tuple(&obj->d, "Direction");
	print_tuple(&obj->top, "Top :");
	print_tuple(&obj->o_obj, "Origin_obj");
	print_tuple(&obj->top_obj, "Top_obj");
	printf("Diam = %lf | Height = %lf\n", obj->diam, obj->height);
	printf("FOV = %lf | color = %d | ratio = %lf\n", obj->FOV, obj->color,
		obj->ratio);
	print_matrix_4(obj->wtoo_m, "wtoo");
	print_matrix_4(obj->otow_m, "otow");
}

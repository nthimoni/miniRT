/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:41:10 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/17 17:56:20 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>
#include <unistd.h>
#include "data_struct.h"
#include "error.h"
#include "exit_rt.h"

static int	check_nb_arg(t_otype type, int nb_wrds)
{
	static const int	tab[] = {3, 4, 4, 4, 4, 6, 6, 2};
	static const t_otype	otype[] = {AMBIANT, CAMERA, LIGHT, PLAN,
										SPHERE, CYLINDRE, CONE, AA, NONE};
	int i;

	i = 0;
	while (otype[i] && otype[i] != type)
		i++;
	if (tab[i] == nb_wrds)
		return (1);
	return (0);
}

static int	fill_obj(char **sp, t_obj *tmp, t_rt *rt)
{
	int	error;

	error = 0;
	if (!check_nb_arg(tmp->type, ft_strslen(sp)))
		return (free(tmp), 1);
	if (tmp->type == AMBIANT)
		error = fill_light(tmp, rt, sp);
	else if (tmp->type == CAMERA)
		error = fill_cam(tmp, rt, sp);
	else if (tmp->type == LIGHT)
		error = fill_light(tmp, rt, sp);
	else if (tmp->type == PLAN)
		error = fill_plan(tmp, rt, sp);
	else if (tmp->type == SPHERE)
		error = fill_sphere(tmp, rt, sp);
	else if (tmp->type == CYLINDRE)
		error = fill_cylindre(tmp, rt, sp);
	else if (tmp->type == CONE)
		error = fill_cone(tmp, rt, sp);
	else if (tmp->type == AA)
		error = fill_aa(tmp, rt, sp);
	return (error);
}

static int	set_type(char **sp, t_scene *scene, t_rt *rt)
{
	static const char		*type[] = {"A", "C", "L", "pl", "sp", "cy", "co",
										"anti-aliasing", NULL};
	static const t_otype	otype[] = {AMBIANT, CAMERA, LIGHT,
										PLAN, SPHERE, CYLINDRE, CONE, AA};
	int 					i;
	t_obj					*tmp;

	i = 0;
	while (type[i] && ft_strncmp(type[i], *sp, 3))
		i++;
	tmp = creat_obj(otype[i]);
	if (!tmp)
	{
		free_split(sp);
		exit_parsing(rt, BAD_ALLOC_MSG, BAD_ALLOC);
	}
	if (fill_obj(sp, tmp, rt))
		return (1);
	(void)scene;
	return (0);
}

static void	fill_scene(char *line, t_scene *scene, t_rt *rt)
{
	char	**sp;

	sp = ft_split(line, ' ');
	if (!sp)
		exit_parsing(rt, BAD_ALLOC_MSG, BAD_ALLOC);
	if (!*sp)
		return (free_split(sp));
	if (set_type(sp, scene, rt))
	{
		free_split(sp);
		exit_parsing(rt, PARSE_ERROR_MSG, PARSE_ERROR);
	}
	free_split(sp);
}

void	parsing(t_rt *rt, char *file, t_scene *scene)
{
	char	*line;

	rt->fd = open(file, O_RDONLY);
	if (rt->fd == -1)
		exit_parsing(rt, OPEN_FAILED_MSG, OPEN_FAILED);
	line = get_next_line(rt->fd);
	while (line)
	{
		if (*line == '-')
		{
			free(line);
			line = get_next_line(rt->fd);
			continue ;	
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		fill_scene(line, scene, rt);
		free(line);
		line = get_next_line(rt->fd);
	}
	if (rt->scn.cam.d.x == 0 && rt->scn.cam.d.y == 0 && rt->scn.cam.d.z == 0)
		exit_parsing(rt, PARSE_ERROR_MSG, PARSE_ERROR);
	close(rt->fd);
}

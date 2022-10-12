/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:41:10 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/11 21:05:03 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>
#include <unistd.h>
#include "miniRT.h"
#include "error.h"
#include "exit_rt.h"

static int	check_nb_arg(t_otype type, int nb_wrds)
{
	static const int	tab[] = {3, 4, 4, 4, 4, 6};
	static const t_otype	otype[] = {AMBIANT, CAMERA, LIGHT,
										PLAN, SPHERE, CYLINDRE, NONE};
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
	if (!check_nb_arg(tmp->type, ft_strslen(sp)))
		return (1);
}

static int	set_type(char **sp, t_scene *scene, t_rt *rt)
{
	static const char		*type[] = {"A", "C", "L", "pl", "sp", "cy", NULL};
	static const t_otype	otype[] = {AMBIANT, CAMERA, LIGHT,
										PLAN, SPHERE, CYLINDRE};
	int 					i;
	t_obj					*tmp;

	i = 0;
	while (type[i] && !ft_strncmp(type[i], *sp, 3))
		i++;
	tmp = creat_obj(otype[i]);
	if (!tmp)
	{
		free(sp);
		exit_parsing(rt, BAD_ALLOC_MSG, BAD_ALLOC);
	}
	if (fill_obj(sp, tmp, rt))
		return (1);
	return (0);
}

static void	fill_scene(char *line, t_scene *scene, t_rt *rt)
{
	char	**sp;

	sp = ft_split(line, ' ');
	if (!sp)
		exit_parsing(rt, BAD_ALLOC_MSG, BAD_ALLOC);
	if (set_type(sp, scene, rt))
	{
		free(sp);
		exit_parsing(rt, PARSE_ERROR_MSG, PARSE_ERROR);
	}
	free(sp);
}

void	parsing(t_rt *rt, char *file, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_parsing(rt, OPEN_FAILED_MSG, OPEN_FAILED);
	line = get_next_line(fd);
	while (line)
	{
		fill_scene(line, scene, rt);
		free(line);
		line = get_next_line(fd);
		if (!line)
			exit_parsing(rt, BAD_ALLOC_MSG, BAD_ALLOC);
	}
}

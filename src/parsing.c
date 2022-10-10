/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:41:10 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/10 19:15:03 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>
#include <unistd.h>
#include "miniRT.h"
#include "error.h"
#include "exit_rt.h"

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
		fill_scene(line, scene);
		line = get_next_line(fd);
		if (!line)
			exit_parsing(rt, BAD_ALLOC_MSG, BAD_ALLOC);
	}
}

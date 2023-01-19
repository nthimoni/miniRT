/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:03:15 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/19 04:01:54 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "mlx.h"

static void	free_obj_lst(t_rt *rt)
{
	t_list	*tmp;
	t_obj	*obj;

	tmp = rt->scn.objs;
	while (tmp)
	{
		obj = tmp->content;
		if (obj->bump)
			mlx_destroy_image(rt->mlx, obj->img_bump.img);
		if (obj->text == TEXTURE)
			mlx_destroy_image(rt->mlx, obj->img_text.img);
		tmp = tmp->next;
	}
	ft_lstclear(&rt->scn.objs, free);
}

void	free_scene(t_rt *rt)
{
	free_obj_lst(rt);
	ft_lstclear(&rt->scn.light, free);
	ft_bzero(&rt->scn, sizeof(t_scene));
}

void	exit_rt(t_rt *rt)
{
	free_scene(rt);
	mlx_destroy_image(rt->mlx, rt->img->img);
	mlx_destroy_window(rt->mlx, rt->win);
	mlx_destroy_display(rt->mlx);
	free(rt->mlx);
	free(rt->img);
	free(rt);
}

void	exit_parsing(t_rt *rt, char *error_msg, int exit_code)
{
	char	*s;

	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	if (rt->fd != -1)
	{
		s = get_next_line(rt->fd);
		while (s)
		{
			free(s);
			s = get_next_line(rt->fd);
		}
		close(rt->fd);
	}
	exit_rt(rt);
	exit(exit_code);
}

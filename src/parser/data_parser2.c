/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:34:14 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/19 04:03:39 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "color.h"
#include "mlx.h"

int	load_img(t_rt *rt, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(rt->mlx, path, &img->x, &img->y);
	if (!img->img)
		return (ft_printf("unnable to open : %s\n", path), 1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_lgth, &img->endian);
	return (0);
}

int	define_bump(t_rt *rt, char *s, t_obj *tmp)
{
	char	**sp;

	sp = ft_split(s, '|');
	if (ft_strslen(sp) > 2)
		return (free_split(sp), 1);
	if (ft_strslen(sp) == 2)
	{
		*ft_strchr(s, '|') = 0;
		if (load_img(rt, sp[1], &tmp->img_bump))
			return (free_split(sp), 1);
		tmp->bump = 1;
	}
	if (ft_strncmp(sp[0] + ft_strlen(sp[0]) - 4, ".xpm", 5))
		return (free_split(sp), 0);
	if (load_img(rt, sp[0], &tmp->img_text))
		return (free_split(sp), 1);
	tmp->text = TEXTURE;
	return (free_split(sp), 0);
}

int	only_nb(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	parse_rgb(char **sp, int *color)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(sp[0]);
	g = ft_atoi(sp[1]);
	b = ft_atoi(sp[2]);
	free_split(sp);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	*color = create_trgb(0, r, g, b);
	return (0);
}

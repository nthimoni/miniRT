/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:54:33 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/10 15:56:49 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "test.h"

int	main(void)
{
	t_rt	*rt;

	rt = NULL;
	ft_printf("Hello World!\n");
	rt = init_rt();
	clear_image(rt);
	test3(rt);
	(void)rt;
	mlx_loop(rt->mlx);
	ft_split("ok", ' ');
	return (0);
}

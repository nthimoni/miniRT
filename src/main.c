/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:54:33 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/18 15:06:36 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "init.h"
#include "mlx.h"
#include "test.h"
#include "ray.h"
#include "data_struct.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_rt	*rt;

	float a = 10;
	if (ft_atof("1", &a))
		ft_printf("OVERFLOW\n\n");
	printf("val : %f\n", a);
	if (ft_atof("0.8", &a))
		ft_printf("OVERFLOW\n\n");
	printf("val : %f\n", a);
	if (ft_atof("0.9", &a))
		ft_printf("OVERFLOW\n\n");
	printf("val : %f\n", a);
	rt = NULL;
	ft_printf("Hello World!\n");
	rt = init_rt();
	init_inter(rt);
	if (argc > 1)
		parsing(rt, argv[1], &rt->scn);
	(void)rt;
	mlx_loop(rt->mlx);
	ft_split("ok", ' ');
	{
		char *s = ".0";
		printf("%s\n", s);
		float a = 0;
		if (ft_atof(s, &a))
			printf("OVERFLOW\n");
		else
			printf("%.50f\n", a);
	}
	{
		char *s = ".005";
		printf("%s\n", s);
		float a = 0;
		if (ft_atof(s, &a))
			printf("OVERFLOW\n");
		else
			printf("%.50f\n", a);
	}
	{
		char *s = ".05";
		printf("%s\n", s);
		float a = 0;
		if (ft_atof(s, &a))
			printf("OVERFLOW\n");
		else
			printf("%.50f\n", a);
	}
	{
		char *s = "13.0";
		printf("%s\n", s);
		float a = 0;
		if (ft_atof(s, &a))
			printf("OVERFLOW\n");
		else
			printf("%.50f\n", a);
	}
	{
		char *s = "13.657";
		printf("%s\n", s);
		float a = 0;
		if (ft_atof(s, &a))
			printf("OVERFLOW\n");
		else
			printf("%.50f\n", a);
	}
	{
		char *s = ".3";
		printf("%s\n", s);
		float a = 0;
		if (ft_atof(s, &a))
			printf("OVERFLOW\n");
		else
			printf("%.50f\n", a);
	}
	{
		char *s = ".33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333";
		printf("%s\n", s);
		float a = 0;
		if (ft_atof(s, &a))
			printf("OVERFLOW\n");
		else
			printf("%.50f\n", a);
	}
	{
		char *s = "333333333333333333333333333333333333333333333333333333333333333333333.3";
		printf("%s\n", s);
		float a = 0;
		if (ft_atof(s, &a))
			printf("OVERFLOW\n");
		else
			printf("%.50f\n", a);
	}
	return (0);
}

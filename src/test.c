/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:56:21 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/05 19:20:37 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "test.h"
#include "print.h"

t_decimal	**create_matrix_x(int x)
{
	t_decimal	**array;
	int			i;

	array = malloc(sizeof(t_decimal *) * (x + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < x)
	{
		array[i] = malloc(sizeof(t_decimal) * x);
		if (!array[i])
			return (NULL);
		ft_bzero(array[i], sizeof(t_decimal) * x);
		i++;
	}
	array[x] = NULL;
	return (array);
}

int	size_matrix(t_decimal **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i - 1);
}

void	fill_matrix_x(t_decimal **array, int sz)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sz)
	{
		while (j < sz)
		{
			array[i][j] = (t_decimal)(i + j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	test(t_rt *rt)
{
	t_decimal	**array;
	t_tuple		*p1;
	t_tuple		*p2;
	t_tuple		*p3;
	t_tuple		*p4;
	t_tuple		*v1;
	t_tuple		*v2;
	t_tuple		*v3;
	t_tuple		*v4;
	t_tuple		*v5;
	t_tuple		*v6;
	t_decimal	arr1[4] = {1, 0, 0, 1};
	t_decimal	arr2[4] = {0, 1, 0, 1};
	t_decimal	arr3[4] = {0, 0, 1, 1};
	t_decimal	arr4[4] = {1, 1, 1, 1};
	t_decimal	arr5[4] = {1, 2, 3, 0};
	t_decimal	arr6[4] = {2, 3, 4, 0};

	array = create_matrix_x(4);
	fill_matrix_x(array, 4);
	print_matrix4(array);
	p1 = create_tuple(arr1, rt);
	p2 = create_tuple(arr2, rt);
	p3 = create_tuple(arr3, rt);
	p4 = create_tuple(arr4, rt);
	v1 = create_v3(p1, p2, rt);
	v2 = create_v3(p2, p1, rt);
	v3 = create_tuple(arr5, rt);
	v4 = create_tuple(arr6, rt);
	v5 = cross_product_v3(v3, v4, rt);
	v6 = norm_v3(v3, rt);
	print_tuple(p1, "p1");
	print_tuple(p2, "p2");
	print_tuple(p3, "p3");
	print_tuple(p4, "p4");
	print_tuple(v1, "v1");
	print_tuple(v2, "v2");
	print_tuple(v3, "v3");
	print_tuple(v4, "v4");
	print_tuple(v5, "v5");
	print_tuple(v6, "v6");
	printf("Length v1 = %lf\n", length_v3(v1));
	printf("Length v4 = %lf\n", length_v3(v4));
	printf("Length v6 = %lf\n", length_v3(v6));
	(void)rt;
}

void	test2(t_rt *rt)
{
	t_proj	*proj;
	t_tuple	*gravity;
	t_tuple	*wind;
	t_decimal		arr1[4] = {0, 10, 0, 1};
	t_decimal		arr2[4] = {10, 10, 0, 0};
	t_decimal		arr3[4] = {0, -1, 0, 0};
	t_decimal		arr4[4] = {-0.1, 0, 0, 0};
	int	i;

	i = 0;
	proj = malloc(sizeof(t_proj));
	if (!proj)
		return ;
	proj->position = create_tuple(arr1, rt);
	proj->velocity = create_tuple(arr2, rt);
	gravity = create_tuple(arr3, rt);
	wind = create_tuple(arr4, rt);
	while (i < 10)
	{
		my_mlx_pixel_put(rt, (int)proj->position->x, (int)proj->position->y, 
				create_trgb(0, 255, 0, 0));
		tick_environment(proj, gravity, wind, rt);
		i++;
	}
	free(wind);
	free(gravity);
}

void	tick_environment(t_proj *proj, t_tuple *gravity, t_tuple *wind, t_rt *rt)
{
	void	*tmp1;
	void	*tmp2;

	tmp1 = proj->position;
	print_tuple(proj->position, "position");
	proj->position = add_v3(proj->position, proj->velocity, rt);
	free(tmp1);
	print_tuple(proj->position, "position");
	tmp2 = proj->velocity;
	proj->velocity = add_v3(proj->velocity, gravity, rt);
	free(tmp2);
	tmp2 = proj->velocity;
	proj->velocity = add_v3(proj->velocity, wind, rt);
	free(tmp2);
}

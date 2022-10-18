/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:20:19 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/18 23:10:45 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	scale_color(int color, double coef)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_t(color) * coef;
	r = get_r(color) * coef;
	g = get_g(color) * coef;
	b = get_b(color) * coef;
	return (create_trgb(t, r, g, b));
}

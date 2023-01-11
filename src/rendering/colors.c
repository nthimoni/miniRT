/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:20:19 by rmorel            #+#    #+#             */
/*   Updated: 2022/10/26 19:30:04 by nthimoni         ###   ########.fr       */
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

	if (get_t(color) * coef > 255.0)
		t = 255;
	else
		t = get_t(color) * coef;
	if (get_r(color) * coef > 255.0)
		r = 255;
	else
		r = get_r(color) * coef;
	if (get_g(color) * coef > 255.0)
		g = 255;
	else
		g = get_g(color) * coef;
	if (get_b(color) * coef > 255.0)
		b = 255;
	else
		b = get_b(color) * coef;
	return (create_trgb(t, r, g, b));
}

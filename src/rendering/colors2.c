/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:29:47 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/19 02:30:23 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

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

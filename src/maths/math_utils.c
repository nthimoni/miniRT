/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:15:51 by rmorel            #+#    #+#             */
/*   Updated: 2023/01/10 19:19:51 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"

t_u	max_u(t_u a, t_u b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_u	min_u(t_u a, t_u b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

t_u	abs_u(t_u n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	clamp(t_u *x)
{
	if (*x > -EPS && *x < EPS)
		*x = +0.0;
	if (*x > 1 - EPS && *x < 1 + EPS)
		*x = 1;
	if (*x > -1 - EPS && *x < -1 + EPS)
		*x = -1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:09:11 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/10 15:43:01 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdio.h>
#include <math.h>

static char	*fill_integer_part(char *str, float *val)
{
	while (*str && *str != '.')
	{
		*val *= 10.f;
		*val += (float)*str - '0';
		str++;
	}
	return (str);
}

static void	fill_floating_point_part(char *str, float *val)
{
	int		i;
	float	tmp;

	i = 1;
	tmp = 0.f;
	while (str[i])
	{
		tmp += ((float)str[i] - '0') / ((pow(10.0, i)));
		i++;
	}
	*val += tmp;
}

static int	fill_val(char *str, float *val)
{
	str = fill_integer_part(str, val);
	if (*str == '.')
		fill_floating_point_part(str, val);
	return (0);
}

static int	check_overflow(char *str, int sign)
{
	static const char	*max_float = "340282346638528859811704183484516925440";
	int					cmp;
	char				**sp;

	sp = ft_split(str, '.');
	if (sp[0])
		str = sp[0];
	if (ft_strlen(str) > ft_strlen(max_float))
		return (free_split(sp), sign);
	if (ft_strlen(str) < ft_strlen(max_float))
		return (free_split(sp), 0);
	cmp = ft_strncmp(str, max_float, ft_strlen(max_float));
	if (cmp > 0)
		return (sign);
	return (0);
}

int	ft_atof(char *str, float *val)
{
	int	sign;
	int	over;

	if (!isValidLiteral(str))
		return (1);
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str == '0')
		str++;
	over = check_overflow(str, sign);
	if (over)
		return (over);
	*val = 0;
	fill_val(str, val);
	*val *= sign;
	return (*val = 0, fill_val(str, val), *val *= sign, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:31:59 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/10 15:51:46 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	free_split(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

int	isValidLiteral(char *str)
{
	int	point;
	int	i;

	if (!str || *str == '\0')
		return (0);
	point = 0;
	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (point)
				return (0);
			else
				point = 1;
		}
		else if (!ft_isdigit(str[i]))
			break ;
		i++;
	}
	if (!str[i] || (str[i] == 'f' && !str[i + 1]))
		return (1);
	return (0);
}

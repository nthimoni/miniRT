/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:23:51 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/14 02:03:30 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

int ft_strslen(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		i++;
	return (i);
}

t_obj	*creat_obj(t_otype type)
{
	t_obj *ret;

	ret = malloc(sizeof(t_obj));
	if (!ret)
		return (NULL);
	ft_bzero((ret), sizeof(*ret));
	ret->type = type;
	return (ret);
}

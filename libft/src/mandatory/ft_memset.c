/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:31:23 by nthimoni          #+#    #+#             */
/*   Updated: 2021/11/26 12:24:07 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)pointer;
	i = 0;
	while (i < count)
	{
		ptr[i] = (char)value;
		i++;
	}
	return (pointer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:29:59 by nthimoni          #+#    #+#             */
/*   Updated: 2021/11/26 12:25:49 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	unsigned int	i;
	char			*dst;
	char			*src;

	if (destination == NULL && source == NULL)
		return (NULL);
	dst = (char *)destination;
	src = (char *)source;
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (destination);
}

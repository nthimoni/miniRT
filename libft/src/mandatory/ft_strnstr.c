/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:10:14 by nthimoni          #+#    #+#             */
/*   Updated: 2021/11/26 19:20:26 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	a;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (str[i] && i < len)
	{
		a = 0;
		while (str[i + a] == to_find[a] && (i + a) < len)
		{
			if (to_find[a + 1] == '\0')
				return ((char *)(str + i));
			a++;
		}
		i++;
	}
	return (NULL);
}

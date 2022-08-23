/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:42:35 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/09 06:16:08 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sublen;
	char	*sub;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	sublen = ft_strlen(s + start);
	if (sublen > len)
		sublen = len;
	sub = malloc(sublen + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, sublen + 1);
	return (sub);
}

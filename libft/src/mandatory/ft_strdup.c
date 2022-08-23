/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:48:30 by nthimoni          #+#    #+#             */
/*   Updated: 2021/11/24 21:48:36 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ret;
	int		len;

	len = ft_strlen(src);
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	if (ret)
	{
		ft_strlcpy(ret, src, len + 1);
		return (ret);
	}
	else
		return (0);
}

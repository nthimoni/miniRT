/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:58:26 by nthimoni          #+#    #+#             */
/*   Updated: 2021/11/26 16:02:55 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	nb_size(int a)
{
	size_t	len;

	if (a == 0)
		return (2);
	len = 0;
	if (a < 0)
		len++;
	while (a != 0)
	{
		a /= 10;
		len++;
	}
	return (len + 1);
}

static	void	fill_str(char *str, int val, size_t len)
{
	long int	signe;
	long int	a;

	a = val;
	signe = 1;
	if (a < 0)
	{
		signe = -1;
		a = -a;
	}
	str[--len] = '\0';
	while (len > 0)
	{
		str[--len] = a % 10 + '0';
		a /= 10;
	}
	if (signe == -1)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ret;

	len = nb_size(n);
	ret = malloc(len);
	if (!ret)
		return (NULL);
	fill_str(ret, n, len);
	return (ret);
}

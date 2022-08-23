/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:19:56 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/11 02:42:05 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	wrdcnt(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static	char	*cpywrd(char const *s, char c)
{
	char	*wrd;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	wrd = malloc(sizeof(char) * (len + 1));
	if (!wrd)
		return (NULL);
	ft_memcpy(wrd, s, len);
	wrd[len] = '\0';
	return (wrd);
}

char	**free_part_tab(char **ret, int a)
{
	while (--a >= 0)
		free(ret[a]);
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	a;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (wrdcnt(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			ret[a] = cpywrd(s + i, c);
			if (!ret[a++])
				return (free_part_tab(ret, a));
			while (s[i + 1] && s[i + 1] != c)
				i++;
		}
		i++;
	}
	ret[a] = NULL;
	return (ret);
}

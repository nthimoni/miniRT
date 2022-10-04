/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:59:49 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/04 15:00:36 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"
#include "exit_rt.h"

void	add_to_trash(t_rt *rt, void *ptr)
{
	t_list	*new;

	new = ft_lstnew(ptr);
	if (!new)
		exit_rt(rt, BAD_ALLOC_MSG, BAD_ALLOC);
	ft_lstadd_back(&rt->trash, new);
}

void	free_trash(t_list *trash)
{
	t_list *tmp;

	while (trash)
	{
		tmp = trash->next;
		free(trash->content);
		free(trash);
		trash = tmp;
	}
}

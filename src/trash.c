/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:59:49 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/05 14:19:43 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exit_rt.h"
#include "trash.h"
#include "error.h"

void	add_to_trash(t_list **trash, void *ptr)
{
	t_list	*new;

	new = ft_lstnew(ptr);
	if (!new)
		exit_rt(*trash, BAD_ALLOC_MSG, BAD_ALLOC);
	ft_lstadd_back(trash, new);
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

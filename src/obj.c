/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bek <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:07:02 by bek               #+#    #+#             */
/*   Updated: 2022/10/21 11:17:05 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	transform_obj_wtoo(t_rt *rt)
{
	t_list	*tmp;
	t_obj	*obj;

	tmp = rt->scn.objs;
	while (tmp)
	{
		obj = tmp->content;
		mult_tuple_matrix_4(&obj->o, obj->wtoo_m, obj->o);
		print_tuple(&obj->o, "objo");
		tmp = tmp->next;
	}
}

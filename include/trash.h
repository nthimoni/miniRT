/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:06:33 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/03 18:07:43 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASH_H
# define TRASH_H 

#include "libft.h"

void	add_to_trash(t_list **trash, void *ptr);
void	free_trash(t_list *trash);

#endif 

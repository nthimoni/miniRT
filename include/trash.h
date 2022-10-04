/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:06:33 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/04 15:01:46 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASH_H
# define TRASH_H 

# include "libft.h"
# include "miniRT.h"

void	add_to_trash(t_rt *rt, void *ptr);
void	free_trash(t_list *trash);

#endif 

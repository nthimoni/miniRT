/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:08:04 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/14 13:30:21 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_RT_H
# define EXIT_RT_H 

# include	"libft.h"
# include "data_struct.h"
# include "trash.h"

void	exit_rt(t_rt *rt, char *error_msg, int exit_code);
void	exit_parsing(t_rt *rt, char *error_msg, int exit_code);

#endif 

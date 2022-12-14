/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:02 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/15 21:44:51 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H 


# include "libft.h"
# include "data_struct.h"

void	parsing(t_rt *rt, char *file, t_scene *scene);
int 	ft_strslen(char **sp);
t_obj	*creat_obj(t_otype type);
int		ft_atof(char *str, float *val);
void	free_split(char **sp);
int	get_ori(char *s, t_tuple *ori);
int get_ratio(char *s, double *ratio);
int get_pos(char *s, t_tuple *pos);
int	get_color(char *s, int *color, t_text *text);
int isValidLiteral(char *str);
int fill_light(t_obj *tmp, t_rt *rt, char **sp);
int fill_cam(t_obj *tmp, t_rt *rt, char **sp);
int fill_plan(t_obj *tmp, t_rt *rt, char **sp);
int fill_sphere(t_obj *tmp, t_rt *rt, char **sp);
int fill_cylindre(t_obj *tmp, t_rt *rt, char **sp);

#endif 

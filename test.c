/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:15:56 by nthimoni          #+#    #+#             */
/*   Updated: 2022/10/13 18:55:41 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%s\n", argv[1]);
	float a = 0;
	if (ft_atof(argv[1], &a))
		printf("OVERFLOW!\n");
	else
		printf("%.15f\n", a);
	printf("%.15f\n", atof(argv[1]));
}

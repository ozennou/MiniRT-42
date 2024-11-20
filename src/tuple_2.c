/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:45:40 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/07 21:57:17 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	dot(t_tuple a, t_tuple b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

t_tuple	cross(t_tuple a, t_tuple b)
{
	t_tuple	t;

	t.x = a.y * b.z - a.z * b.y;
	t.y = a.z * b.x - a.x * b.z;
	t.z = a.x * b.y - a.y * b.x;
	t.w = 0;
	return (t);
}

t_tuple	color(double r, double g, double b)
{
	if (r < 0)
		r = 0;
	else if (r > 1)
		r = 1;
	if (g < 0)
		g = 0;
	else if (g > 1)
		g = 1;
	if (b < 0)
		b = 0;
	else if (b > 1)
		b = 1;
	return ((t_tuple){r, g, b, 0});
}

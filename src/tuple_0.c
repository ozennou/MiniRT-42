/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:34:50 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/06 14:18:54 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tuple	point(double x, double y, double z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 1;
	return (t);
}

t_tuple	vector(double x, double y, double z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 0;
	return (t);
}

t_tuple	add(t_tuple a, t_tuple b)
{
	t_tuple	t;

	t.x = a.x + b.x;
	t.y = a.y + b.y;
	t.z = a.z + b.z;
	t.w = a.w + b.w;
	return (t);
}

// used for color addition
t_tuple	harmard(t_tuple a, t_tuple b)
{
	t_tuple	t;

	t.x = a.x * b.x;
	t.y = a.y * b.y;
	t.z = a.z * b.z;
	t.w = a.w * b.w;
	return (t);
}

t_tuple	sub(t_tuple a, t_tuple b)
{
	t_tuple	t;

	t.x = a.x - b.x;
	t.y = a.y - b.y;
	t.z = a.z - b.z;
	t.w = a.w - b.w;
	return (t);
}

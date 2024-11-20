/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:41:58 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/08 18:45:49 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tuple	neg(t_tuple a)
{
	t_tuple	t;

	t.x = -a.x;
	t.y = -a.y;
	t.z = -a.z;
	t.w = -a.w;
	return (t);
}

t_tuple	multiply(t_tuple a, double b)
{
	t_tuple	t;

	t.x = a.x * b;
	t.y = a.y * b;
	t.z = a.z * b;
	t.w = a.w * b;
	return (t);
}

t_tuple	divide(t_tuple a, double b)
{
	return (multiply(a, 1 / b));
}

double	magnitude(t_tuple a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_tuple	normalize(t_tuple a)
{
	if (magnitude(a) == 0)
		return (a);
	return (divide(a, magnitude(a)));
}

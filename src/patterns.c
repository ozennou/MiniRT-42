/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:55:34 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/07 21:56:27 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tuple	func(t_tuple a, t_tuple b, t_tuple point)
{
	t_tuple	res;

	res.x = a.x + (b.x - a.x) * (point.x - (int)point.x);
	res.y = a.y + (b.y - a.y) * (point.y - (int)point.y);
	res.z = a.z + (b.z - a.z) * (point.z - (int)point.z);
	return (res);
}

t_tuple	stripe_at_object(t_tuple a, t_tuple b, t_all *all, int i)
{
	t_sphere	*s;
	t_plane		*p;
	t_tuple		object_p;
	t_tuple		pattern_p;

	if (i)
		return (func(a, b, a));
	if (all->object->type == SPHERE)
	{
		s = all->object->object;
		object_p = multi_m_p(s->transform, all->point);
	}
	else if (all->object->type == PLANE)
	{
		p = all->object->object;
		object_p = multi_m_p(p->transform, all->point);
	}
	return (stripe_at(a, b, object_p));
}

t_tuple	stripe_at(t_tuple a, t_tuple b, t_tuple point)
{
	int	t;

	t = point.x * 15;
	if (!(t % 2) && point.x < 0)
		return (a);
	else if (t % 2 && point.x < 0)
		return (b);
	else if (!(t % 2) && point.x > 0)
		return (b);
	else if (t % 2 && point.x > 0)
		return (a);
	return (b);
}

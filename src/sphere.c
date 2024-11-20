/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:22:18 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/07 22:31:23 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_sphere	init_sphere(t_tuple	p, double r)
{
	t_sphere	res;

	res.p = p;
	res.r = r;
	res.transform = identity(4);
	return (res);
}

void	set_tranform(void *v, t_matrix m, int type)
{
	t_sphere	*s;
	t_plane		*pl;
	t_cylinder	*c;
	t_cone		*co;

	if (type == SPHERE)
	{
		s = v;
		s->transform = inversion(s->transform);
		s->transform = multi(s->transform, m);
		s->transform = inversion(s->transform);
	}
	else if (type == PLANE)
	{
		pl = v;
		pl->transform = inversion(pl->transform);
		pl->transform = multi(pl->transform, m);
		pl->transform = inversion(pl->transform);
	}
	else if (type == CYLINDER)
	{
		c = v;
		c->transform = inversion(c->transform);
		c->transform = multi(c->transform, m);
		c->transform = inversion(c->transform);
	}
	else if (type == CONE)
	{
		co = v;
		co->transform = inversion(co->transform);
		co->transform = multi(co->transform, m);
		co->transform = inversion(co->transform);
	}
}

t_tuple	normal_at(t_sphere s, t_tuple p)
{
	t_tuple	normal;
	t_tuple	obj_point;
	t_tuple	obj_normal;

	obj_point = multi_m_p((s.transform), p);
	obj_normal = sub(obj_point, s.p);
	normal = multi_m_p(transpose((s.transform)), obj_normal);
	normal.w = 0;
	return (normalize(normal));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkersboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:47:07 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/07 21:25:14 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (sub(in, multiply(normal, 2 * dot(in, normal))));
}

void	spherical_map(t_all *all, double *u, double *v)
{
	t_sphere	*s;
	double		theta;
	double		radius;
	double		phi;

	s = ((t_sphere *)all->object->object);
	theta = atan2(all->point.x - s->p.x, all->point.z - s->p.z);
	radius = magnitude(normalize(sub(all->point, s->p)));
	phi = acos((all->point.y - s->p.z) / radius);
	(*u) = 1 - (theta / 2 * M_PI) + 0.5;
	(*v) = 1 - phi / M_PI;
}

t_tuple	uv_checker(t_all *all, t_tuple a, t_tuple b)
{
	double	u;
	double	v;
	int		u1;
	int		v1;

	spherical_map(all, &u, &v);
	u1 = floor(u * 2);
	v1 = floor(v * 50);
	if ((u1 + v1) % 2 == 0)
		return (a);
	return (b);
}

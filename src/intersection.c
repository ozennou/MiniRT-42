/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:11:48 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/07 21:25:04 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_intersection	ion(double t, void *object, int type)
{
	t_intersection	inter;
	t_object		obj;

	inter.t = t;
	obj.object = object;
	obj.type = type;
	inter.object = obj;
	return (inter);
}

t_intersection	*intersect_sphere(t_ray r1, t_sphere *s, double teta)
{
	t_tuple			s_to_r;
	t_intersection	*res;
	t_object		obj;
	double			a;
	double			b;

	res = malloc(2 * sizeof(t_intersection));
	if (!res)
		return (exit(1), NULL);
	r1 = transform(r1, s->transform);
	s_to_r = sub(r1.origin, s->p);
	a = dot(r1.direction, r1.direction);
	b = 2.0 * dot(r1.direction, s_to_r);
	teta = b * b - 4 * a * (dot(s_to_r, s_to_r) - s->r * s->r);
	res[0].t = (-b - sqrt(teta)) / (2 * a);
	res[1].t = (-b + sqrt(teta)) / (2 * a);
	obj.object = s;
	obj.type = SPHERE;
	res[0].object = obj;
	res[1].object = obj;
	return (res);
}

t_intersection	*intersect_plane(t_ray r, t_plane *pl)
{
	t_intersection	*res;

	res = malloc(2 * sizeof(t_intersection));
	if (!res)
		return (exit(1), NULL);
	r = transform(r, pl->transform);
	r = transform(r, translate(-pl->p.x, -pl->p.y, -pl->p.z));
	r = transform(r, rotation_x(-pl->normal.x));
	r = transform(r, rotation_y(-pl->normal.y));
	r = transform(r, rotation_z(-pl->normal.z));
	if (fabs(r.direction.y) < EPSILON)
	{
		res[0].t = NAN;
		res[1].t = NAN;
		return (res);
	}
	res[0].t = -r.origin.y / r.direction.y;
	res[1].t = res[0].t;
	res[0].object = (t_object){PLANE, pl};
	res[1].object = (t_object){PLANE, pl};
	return (res);
}

t_intersection	*intersect(t_ray r1, t_object *o)
{
	if (o->type == SPHERE)
		return (intersect_sphere(r1, o->object, 0));
	if (o->type == PLANE)
		return (intersect_plane(r1, o->object));
	return (NULL);
}

double	hit(t_intersection *inter)
{
	if (isnan(inter[0].t) || isnan(inter[1].t))
		return (free(inter), NAN);
	if (inter[0].t < inter[1].t && inter[0].t > 0)
		return (free(inter), inter[0].t);
	else if (inter[1].t > 0)
		return (free(inter), inter[1].t);
	return (free(inter), NAN);
}

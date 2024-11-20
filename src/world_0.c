/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:10:46 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/08 15:37:58 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_world	init_world(void)
{
	return ((t_world){NULL, NULL});
}

void	add_light(t_world *world, t_light *light)
{
	ft_lstadd_front(&(world->lights), ft_lstnew(light));
}

void	add_object(t_world *world, t_object *object)
{
	ft_lstadd_front(&(world->objects), ft_lstnew(object));
}

t_all	prepare_compute(t_world *w, t_ray r)
{
	t_all		a;
	t_object	*o;
	t_list		*tmp;
	double		t;

	a.t = NAN;
	a.object = NULL;
	tmp = w->objects;
	while (tmp)
	{
		o = tmp->content;
		t = hit(intersect(r, o));
		if (!isnan(t) && t > 0 && (t < a.t || isnan(a.t)))
		{
			a.t = t;
			a.object = o;
			a.point = position_at(r, t - EPSILON);
			if (o->type == SPHERE)
				a.normalv = normal_at(*(t_sphere *)(a.object->object), a.point);
			else if (o->type == PLANE)
				a.normalv = ((t_plane *)(a.object->object))->normal;
			a.eyev = neg(r.direction);
			a.over_point = add(a.point, multiply(a.normalv, EPSILON));
		}
		tmp = tmp->next;
	}
	return (a);
}

void	printf_world(t_world *w)
{
	t_light		*l;
	t_object	*o;
	t_sphere	*s;
	t_plane		*p;
	t_cylinder	*cy;
	t_cone		*c;

	while (w->lights)
	{
		l = w->lights->content;
		printf("Light (%f, %f, %f)\n", l->position.x, l->position.y, l->position.z);
		w->lights = w->lights->next;
	}
	while (w->objects)
	{
		o = w->objects->content;
		if (o->type == SPHERE)
		{
			s = o->object;
			printf("Sphere (%f, %f, %f)\n", s->p.x, s->p.y, s->p.z);
		}
		else if(o->type == CYLINDER)
		{
			cy = o->object;
			printf("Cylinder (%f, %f, %f)\n", cy->origin.x, cy->origin.y, cy->origin.z);
		}
		else if(o->type == PLANE)
		{
			p = o->object;
			printf("Plane (%f, %f, %f)\n", p->p.x, p->p.y, p->p.z);
		}
		else if(o->type == CONE)
		{
			c = o->object;
			printf("Cone (%f, %f, %f)\n", c->origin.x, c->origin.y, c->origin.z);
		}
		w->objects = w->objects->next;
	}
}

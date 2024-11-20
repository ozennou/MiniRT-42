/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:40:44 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/08 20:55:09 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


t_tuple	shade_hit(t_world *world, t_ray r, t_all *a)
{
	t_list		*tmp;
	t_tuple		res;
	int			sh;

	tmp = world->lights;
	res = color(0, 0, 0);
	while (tmp)
	{
		if (!a->object)
		{
			tmp = tmp->next;
			continue ;
		}
		sh = is_shadowed(world, a->over_point, *(t_light*)tmp->content);
		if (a->object->type == SPHERE)
			res = add(res, (lighting(((t_sphere *)(a->object->object))->material, *(t_light*)tmp->content, a, sh)));
		else if (a->object->type == CYLINDER)
			res = add(res, multiply(lighting(((t_cylinder *)(a->object->object))->material, *(t_light*)tmp->content, a, sh), 4));
		else if (a->object->type == CONE)
			res = add(res, lighting(((t_cone *)(a->object->object))->material, *(t_light*)tmp->content, a, sh));
		else
		{
			res = lighting_p(((t_plane *)(a->object->object)), (t_light*)tmp->content, a);
			// res = add(res, lighting(((t_plane *)(a->object->object))->material, *(t_light*)tmp->content, a, sh));
		}
		tmp = tmp->next;
	}
	return (res);
}

t_tuple	lighting(t_material m, t_light light, t_all *a, int shadow_in)
{
	t_tuple		effective_color;
	t_tuple		lightv;
	t_tuple		diffuse;
	t_tuple		specular;
	double		reflect_dot_eye;

	effective_color = harmard(m.color, light.intensity);
	lightv = normalize(sub(light.position, a->point));
	if (dot(lightv, a->normalv) < 0 || shadow_in)
		return (multiply(effective_color, m.ambient));
	diffuse = multiply(effective_color, m.diffuse * dot(a->normalv, lightv));
	reflect_dot_eye = dot(reflect(neg(lightv), a->normalv), a->eyev);
	if (reflect_dot_eye <= 0)
		specular = color(0, 0, 0);
	else
	{
		specular = multiply(light.intensity, m.specular
				* pow(reflect_dot_eye, m.shininess));
	}
	return (add(add(multiply(effective_color, m.ambient), diffuse), specular));
}

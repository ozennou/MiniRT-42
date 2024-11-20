/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:52:10 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/08 15:21:01 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_material	init_material(double ambient, double diffuse, double specular)
{
	t_material	mat;

	if (ambient < 0)
		ambient = 0;
	else if (ambient > 1)
		ambient = 1;
	if (diffuse < 0)
		diffuse = 0;
	else if (diffuse > 1)
		diffuse = 1;
	if (specular < 0)
		specular = 0;
	else if (specular > 1)
		specular = 1;
	mat.ambient = ambient;
	mat.diffuse = diffuse;
	mat.specular = specular;
	mat.shininess = 200;
	return (mat);
}

t_light	point_light(t_tuple position, t_tuple intensity, double brightness)
{
	t_light	light;

	light.position = position;
	light.intensity = multiply(intensity, brightness);
	light.brightness = brightness;
	return (light);
}

int	is_shadowed(t_world *world, t_tuple point, t_light	light)
{
	t_ray	ray;
	t_tuple	vec;
	t_all	a;
	double	dis;

	vec = sub(light.position, point);
	dis = magnitude(vec);
	ray = init_ray(point, normalize(vec));
	a = prepare_compute(world, ray);
	if (!isnan(a.t) && (a.t > 0 && a.t < dis))
		return (1);
	return (0);
}

t_tuple	lighting_p(t_plane *p, t_light *l, t_all *a)
{
	t_tuple	res;
	double	k;

	k = (1 / log10(a->t * M_E) + 1 / a->t * M_E);
	if (k > 1)
		res = harmard(p->material.color, l->intensity);
	else
		res = multiply(harmard(p->material.color, l->intensity), k);
	return (res);
}

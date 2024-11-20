/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:32:58 by mozennou          #+#    #+#             */
/*   Updated: 2024/02/15 10:48:33 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ray	init_ray(t_tuple origin, t_tuple direction)
{
	t_ray	res;

	res.origin = origin;
	res.direction = direction;
	return (res);
}

t_tuple	position_at(t_ray ray, double t)
{
	return (add(ray.origin, multiply(ray.direction, t)));
}

t_ray	transform(t_ray ray, t_matrix m)
{
	t_ray	res;

	res.origin = multi_m_p(m, ray.origin);
	res.direction = multi_m_p(m, ray.direction);
	return (res);
}

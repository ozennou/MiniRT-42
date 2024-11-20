/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:58:41 by mozennou          #+#    #+#             */
/*   Updated: 2024/02/13 14:02:09 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_matrix	translate(double x, double y, double z)
{
	t_matrix	res;

	res = identity(4);
	res.m[0][3] = x;
	res.m[1][3] = y;
	res.m[2][3] = z;
	return (res);
}

t_matrix	scale(double x, double y, double z)
{
	t_matrix	res;

	res = identity(4);
	res.m[0][0] = x;
	res.m[1][1] = y;
	res.m[2][2] = z;
	return (res);
}

t_matrix	rotation_x(double angle)
{
	t_matrix	res;

	res = identity(4);
	res.m[1][1] = cos(angle);
	res.m[1][2] = -sin(angle);
	res.m[2][1] = sin(angle);
	res.m[2][2] = cos(angle);
	return (res);
}

t_matrix	rotation_y(double angle)
{
	t_matrix	res;

	res = identity(4);
	res.m[0][0] = cos(angle);
	res.m[0][2] = sin(angle);
	res.m[2][0] = -sin(angle);
	res.m[2][2] = cos(angle);
	return (res);
}

t_matrix	rotation_z(double angle)
{
	t_matrix	res;

	res = identity(4);
	res.m[0][0] = cos(angle);
	res.m[0][1] = -sin(angle);
	res.m[1][0] = sin(angle);
	res.m[1][1] = cos(angle);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:01:09 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/07 21:56:05 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tuple	multi_m_p(t_matrix m, t_tuple p)
{
	t_tuple	r;

	r = vector(0, 0, 0);
	if (m.size != 4)
		return (r);
	r.x = m.m[0][0] * p.x + m.m[0][1] * p.y + m.m[0][2] * p.z + m.m[0][3] * p.w;
	r.y = m.m[1][0] * p.x + m.m[1][1] * p.y + m.m[1][2] * p.z + m.m[1][3] * p.w;
	r.z = m.m[2][0] * p.x + m.m[2][1] * p.y + m.m[2][2] * p.z + m.m[2][3] * p.w;
	r.w = m.m[3][0] * p.x + m.m[3][1] * p.y + m.m[3][2] * p.z + m.m[3][3] * p.w;
	return (r);
}

t_matrix	transpose(t_matrix m)
{
	t_matrix	res;
	int			i;
	int			j;

	res.size = m.size;
	i = -1;
	while (++i < m.size)
	{
		j = -1;
		while (++j < m.size)
			res.m[j][i] = m.m[i][j];
	}
	return (res);
}

double	cofactor(t_matrix m, int x, int y)
{
	if ((x + y) % 2)
		return (-determinant(submatrix(m, x, y)));
	else
		return (determinant(submatrix(m, x, y)));
}

t_matrix	inversion(t_matrix m)
{
	double		det;
	t_matrix	res;
	int			i;
	int			j;

	det = determinant(m);
	res.size = m.size;
	if (!det)
		return (res);
	i = -1;
	while (++i < m.size)
	{
		j = -1;
		while (++j < m.size)
			res.m[j][i] = cofactor(m, i, j) / det;
	}
	return (res);
}

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	res;

	forward = normalize(sub(to, from));
	left = cross(forward, normalize(up));
	true_up = cross(left, forward);
	res = identity(4);
	print_matrix(res);
	res.m[0][0] = left.x;
	res.m[0][1] = left.y;
	res.m[0][2] = left.z;
	res.m[1][0] = true_up.x;
	res.m[1][1] = true_up.y;
	res.m[1][2] = true_up.z;
	res.m[2][0] = -forward.x;
	res.m[2][1] = -forward.y;
	res.m[2][2] = -forward.z;
	return (multi(res, translate(-from.x, -from.y, -from.z)));
}

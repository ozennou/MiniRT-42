/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:08:56 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/07 21:55:54 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_matrix	init_matrix(int n)
{
	t_matrix	res;
	int			i;
	int			j;

	if (n <= 0 || n > 4)
		n = 4;
	res.size = n;
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			res.m[i][j] = 0;
	}
	return (res);
}

t_matrix	submatrix(t_matrix m, int row, int col)
{
	t_matrix	t;
	int			i;
	int			j;
	int			x;
	int			y;

	t.size = m.size - 1;
	i = 0;
	x = 0;
	while (i < m.size)
	{
		if (i == row && ++i)
			continue ;
		y = 0;
		j = 0;
		while (j < m.size)
		{
			if (j == col && ++j)
				continue ;
			t.m[x][y++] = m.m[i][j++];
		}
		i++;
		x++;
	}
	return (t);
}

double	determinant(t_matrix m)
{
	double	det;
	int		i;
	int		sign;

	if (m.size == 2)
		return (m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0]);
	i = -1;
	det = 0;
	while (++i < m.size)
	{
		if (i % 2 == 0)
			sign = 1;
		else
			sign = -1;
		det += sign * m.m[0][i] * determinant(submatrix(m, 0, i));
	}
	return (det);
}

t_matrix	multi(t_matrix a, t_matrix b)
{
	t_matrix	res;
	int			i;
	int			j;
	int			k;
	double		sum;

	res = init_matrix(4);
	if (a.size != b.size)
		return (res);
	res.size = a.size;
	i = -1;
	while (++i < res.size)
	{
		j = -1;
		while (++j < res.size)
		{
			sum = 0;
			k = -1;
			while (++k < res.size)
				sum += a.m[i][k] * b.m[k][j];
			res.m[i][j] = sum;
		}
	}
	return (res);
}

t_matrix	identity(int n)
{
	t_matrix	res;
	int			i;

	if (n <= 0 || n > 4)
		n = 4;
	res = init_matrix(n);
	i = -1;
	while (++i < n)
		res.m[i][i] = 1;
	return (res);
}

void	print_matrix(t_matrix m) //remove
{
	int	i;
	int	j;

	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
			printf("%f ", m.m[i][j++]);
		printf("\n");
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:38:09 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/07 21:56:12 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	destroy(t_struct *fc)
{
	mlx_destroy_image(fc->mlx, fc->img);
	mlx_destroy_window(fc->mlx, fc->win);
	// my_malloc(0, 1);
	exit(0);
	return (0);
}

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->bf + (y * data->ln_b + x * (data->pxl_b / 8));
	*(unsigned int *) dst = color;
}

int	keyclick(int key, void *ptr)
{
	t_struct	*fc;

	fc = ptr;
	if (key == KEY_ESC)
		destroy(fc);
	return (0);
}

void	even_init(t_struct *fc)
{
	mlx_hook(fc->win, ON_KEYDOWN, 0, &keyclick, fc);
	mlx_hook(fc->win, ON_DESTROY, 0, &destroy, fc);
}

int	init_graphics(t_struct *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (1);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "MiniRT");
	if (!mlx->win)
		return (1);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img)
		return (1);
	return (0);
}

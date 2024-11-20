/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:01:35 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/08 12:12:21 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_camera	init_camera(t_tuple pos, t_tuple look_at, int degree)
{
	t_camera	res;
	double		half_view;
	double		aspect;

	res.fov = (double)((M_PI * degree) / 180);
	res.pos = pos;
	res.look_at = look_at;
	aspect = (float)WIDTH / (float)HEIGHT;
	half_view = tan(res.fov / 2);
	if (aspect >= 1)
	{
		res.half_width = half_view;
		res.half_height = half_view / aspect;
	}
	else
	{
		res.half_width = half_view * aspect;
		res.half_height = half_view;
	}
	res.pixel_size = (res.half_width * 2) / WIDTH;
	return (res);
}

t_ray	ray_for_pixel(t_camera *c, int x, int y)
{
	double	world_x;
	double	world_y;
	t_tuple	pixel;
	t_tuple	origin;

	world_x = c->half_width - (x + 0.5) * c->pixel_size;
	world_y = c->half_height - (y + 0.5) * c->pixel_size;
	pixel = multi_m_p(translate(c->look_at.x, c->look_at.y, c->look_at.z),
			point(world_x, world_y, -1));
	origin = multi_m_p(translate(c->pos.x, c->pos.y, c->pos.z), c->pos);
	return (init_ray(origin, normalize(sub(pixel, origin))));
}

void	render(t_camera *c, t_world *w, t_img *img, int uv)
{
	t_ray	r;
	t_all	a;
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			r = ray_for_pixel(c, x, y);
			a = prepare_compute(w, r);

			if (!isnan(a.t))
			{
				if (uv)
					pixel_put(img, x, y, to_int(uv_checker(&a, (t_tuple){0, 0, 0, 0}, (t_tuple){1, 1, 1, 0})));
				else 
					pixel_put(img, x, y, to_int(shade_hit(w, r, &a)));
			}
			else
				pixel_put(img, x, y, 0x090909);
			y++;
		}
		x++;
		printf("progress = -----------------> ( %.2f %%) <----------------- \r", \
                (float )((float )(x*y)/((float )HEIGHT * ((float )WIDTH - 1))) * 100);
	}
}

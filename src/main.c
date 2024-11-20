/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:07:34 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/08 20:55:53 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void lol()
{
	system("leaks miniRT");
}


t_plane init_plane(t_tuple normal, t_tuple point)
{
	t_plane	res;

	res.normal = normal;
	res.p = point;
	res.transform = identity(4);
	return (res);
}

int main(int ac, char **av)
{
	int option ;
	t_struct	mlx;
	t_img		img;
	t_all		a;
	t_world		world;
	if (ac == 1) {
		option = 1;
	}
	else if (av[1][0] == '1' && av[1][1] == 0) {
		option = 1;
	}
	else if (av[1][0] == '2' && av[1][1] == 0) {
		option = 2;
	}
	else if (av[1][0] == '3' && av[1][1] == 0) {
		option = 3;
	}
	else if (av[1][0] == '4' && av[1][1] == 0) {
		option = 4;
	}
	else {
		option = 5;
	}
	world = init_world();
	if (init_graphics(&mlx))
		return (1);
	img.bf = mlx_get_data_addr(mlx.img, &img.pxl_b, &img.ln_b, &img.endian);
	t_light l = point_light(point(10, 10, 0), color(1, 1, 1), 0.9);
	t_light l4 = point_light(point(1, 1, -2), color(1, 1, 1), 0.9);
	t_light l3 = point_light(point(-10, 2, -10), color(1, 1, 1), 0.9);
	t_sphere	s = init_sphere(point(-2, 1, 0.6), 0.4);
	s.material = init_material(0.1, 0.9, 0.9);
	s.material.color = color(0.5625, 0.5625, 0.5625);
	t_sphere	s2 = init_sphere(point(0.1, 0, 0), 0.3);
	s2.material = init_material(0.1, 0.9, 0.9);
	s2.material.color = color(1, 0.2, 0);
	t_sphere	s3 = init_sphere(point(0.2, -0.1, 0), 0.2);
	s3.material = init_material(0.1, 0.9, 0.9);
	s3.material.color = color(0, 0.9, 1);
	t_sphere	s4 = init_sphere(point(-0.5, 0, 0), 0.3);
	s4.material = init_material(0.1, 0.9, 0.9);
	s4.material.color = color(1, 0.2, 1);
	t_ray	r;
	r.origin = point(0, 0, -5);
	t_light ll = point_light(point(3, -3, 0), color(1, 1, 1), 0.9);
	
	t_plane p = init_plane(vector(0.2, 1, 0), point(0, -0.4, 0));
	p.material = init_material(0.1, 0.9, 0.9);
	p.material.color = color(0.8, 0.2, 0.8);
	t_plane p1 = init_plane(vector(-1, 1, 0), point(-1.5, -1.5, 0));
	p1.material = init_material(0.1, 0.9, 0.9);
	p1.material.color = color(0, 1, 0.6);
	if (option == 1) {
		add_light(&world, &l3);
		add_object(&world, &(t_object){SPHERE, &s2});
		add_object(&world, &(t_object){PLANE, &p1});
		t_camera cam = init_camera(point(0, 1, -5), vector(-0.1, 0.1, 0), 70);
		render(&cam, &world, &img, 0);
	}
	else if (option == 2) {
		t_plane p = init_plane(vector(0.2, 1.5, 0), point(0, -0.32, 0));
		p.material = init_material(0.1, 0.9, 0.9);
		p.material.color = color(0.8, 0.2, 0.8);
		add_light(&world, &l4);
		add_object(&world, &(t_object){SPHERE, &s2});
		add_object(&world, &(t_object){PLANE, &p});
		t_camera cam = init_camera(point(0, 1, -5), vector(-0.1, 0.1, 0), 70);
		render(&cam, &world, &img, 0);
	}
	else if (option == 3) {
		add_light(&world, &l3);
		t_sphere	s2 = init_sphere(point(-0.1, 0, 0), 0.3);
		s2.material = init_material(0.1, 0.9, 0.9);
		s2.material.color = color(1, 0.2, 0);
		add_object(&world, &(t_object){SPHERE, &s2});
		t_camera cam = init_camera(point(0, 1, -5), vector(-0.1, 0.1, 0), 70);
		render(&cam, &world, &img, 1);
	}
	else if (option == 4) {
		add_light(&world, &l3);
		add_light(&world, &l);
		t_sphere	s2 = init_sphere(point(-0.1, 0, 0), 0.2);
		s2.material = init_material(0.1, 0.9, 0.9);
		s2.material.color = color(1, 0.2, 0);
		t_plane p = init_plane(vector(0.2, 1, 0), point(0, -0.4, 0));
		p.material = init_material(0.1, 0.9, 0.9);
		p.material.color = color(0, 0.2, 0.8);
		add_object(&world, &(t_object){SPHERE, &s2});
		add_object(&world, &(t_object){PLANE, &p});
		t_camera cam = init_camera(point(0, 1, -5), vector(-0.1, 0.1, 0), 70);
		render(&cam, &world, &img, 0);
	}
	else {
		add_light(&world, &l3);
		add_light(&world, &l);
		t_sphere	s2 = init_sphere(point(-0.1, 0, 0), 0.2);
		s2.material = init_material(0.1, 0.9, 0.9);
		s2.material.color = color(1, 0.2, 0);
		t_plane p = init_plane(vector(0.2, 1, 0), point(0, -0.4, 0));
		p.material = init_material(0.1, 0.9, 0.9);
		p.material.color = color(0, 0.2, 0.8);
		t_plane p1 = init_plane(vector(-0.2, 1, 0), point(-1.5, -1.5, 0));
		p1.material = init_material(0.1, 0.9, 0.9);
		p1.material.color = color(0, 1, 0.6);
		add_object(&world, &(t_object){SPHERE, &s2});
		add_object(&world, &(t_object){PLANE, &p});
		add_object(&world, &(t_object){PLANE, &p1});
		t_camera cam = init_camera(point(0, 1, -5), vector(-0.1, 0.1, 0), 70);
		render(&cam, &world, &img, 0);
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	even_init(&mlx);
	mlx_loop(mlx.mlx);
	return 0;
}


// int main()
// {
// 	// atexit(lol);
// 	t_struct	mlx;
// 	t_img		img;
// 	t_all		a;
// 	t_world		world = init_world();
	
// 	if (init_graphics(&mlx))
// 		return (1);
// 	img.bf = mlx_get_data_addr(mlx.img, &img.pxl_b, &img.ln_b, &img.endian);
// 	t_light l = point_light(point(10, 10, 0), color(1, 1, 1), 0.9);
// 	t_light l4 = point_light(point(1, 1, -2), color(1, 1, 1), 0.9);
// 	t_light l3 = point_light(point(-10, 2, -10), color(1, 1, 1), 0.9);
// 	t_sphere	s = init_sphere(point(-2, 1, 0.6), 0.4);
// 	s.material = init_material(0.1, 0.9, 0.9);
// 	s.material.color = color(0.5625, 0.5625, 0.5625);
// 	t_sphere	s2 = init_sphere(point(0.5, 0, 0), 0.2);
// 	s2.material = init_material(0.1, 0.9, 0.9);
// 	s2.material.color = color(1, 0.2, 0);
// 	t_sphere	s3 = init_sphere(point(0.2, -0.1, 0), 0.2);
// 	s3.material = init_material(0.1, 0.9, 0.9);
// 	s3.material.color = color(0, 0.9, 1);
// 	t_sphere	s4 = init_sphere(point(-0.5, 0, 0), 0.3);
// 	s4.material = init_material(0.1, 0.9, 0.9);
// 	s4.material.color = color(1, 0.2, 1);
// 	// set_tranform(&s4, scale(0.5,0.5,0.5), SPHERE);
// 	t_ray	r;
// 	r.origin = point(0, 0, -5);
// 	t_light ll = point_light(point(3, -3, 0), color(1, 1, 1), 0.9);
// 	add_light(&world, &l3);
// 	// add_light(&world, &l4);
// 	// add_light(&world, &ll);
// 	// set_tranform(&s2,scale(2, 2, 2));
	
// 	t_plane p = init_plane(vector(0.16, 1, 0), point(0, -0.4, 0));////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 	p.material = init_material(0.1, 0.9, 0.9);
// 	p.material.color = color(1, 0.2, 0);
// 	t_plane p1 = init_plane(vector(-1, 1, 0), point(-1.5, -1.5, 0));////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 	p1.material = init_material(0.1, 0.9, 0.9);
// 	p1.material.color = color(0, 1, 0.6);
// 	// set_tranform(&p, translate(0, -0.3, 0), PLANE);
// 	// set_tranform(&p, rotation_x(0.05), PLANE);
// 	// add_object(&world, &(t_object){SPHERE, &s});
// 	add_object(&world, &(t_object){SPHERE, &s2});
// 	// add_object(&world, &(t_object){SPHERE, &s3});
// 	// add_object(&world, &(t_object){SPHERE, &s4});
// 	// t_cone cyl = init_cone(point(0, 0, 0), -0.2, 0.2, 0.2);
// 	// set_tranform(&cyl, rotation_z(M_PI_4), CONE);
// 	// add_object(&world, &(t_object){CONE, &cyl});
// 	// set_tranform(&cyl, rotation_x(M_PI_2), CONE);
// 	// set_tranform(&c, rotation_z(0.01), CONE);
// 	// add_object(&world, &(t_object){CONE, &c});
// 	// add_object(&world, &(t_object){PLANE, &p});
// 	add_object(&world, &(t_object){PLANE, &p1});
// 	t_camera cam = init_camera(point(0, 1, -5), vector(-0.1, 0.1, 0), 70);
// 	render(&cam, &world, &img);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
// 	even_init(&mlx);
// 	mlx_loop(mlx.mlx);
// 	return 0;
// }


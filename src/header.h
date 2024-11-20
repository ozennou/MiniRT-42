/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:35:22 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/08 15:20:05 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "structers.h"
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h> ///

# define WIDTH 1500
# define HEIGHT 1000
# define EPSILON .0001

# define KEY_ESC 53

# define ON_DESTROY 17
# define ON_KEYDOWN 2

# define DARK 0xBF000000

enum
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
} ;

void			*my_malloc(size_t size, int mode);
// matrix functions
t_matrix		init_matrix(int n);
t_matrix		submatrix(t_matrix m, int row, int col);
double			determinant(t_matrix m);
t_matrix		multi(t_matrix a, t_matrix b);
t_matrix		identity(int n);
t_matrix		translate(double x, double y, double z);
t_matrix		scale(double x, double y, double z);
t_matrix		rotation_x(double angle);
t_matrix		rotation_y(double angle);
t_matrix		rotation_z(double angle);
t_tuple			multi_m_p(t_matrix m, t_tuple p);
t_matrix		transpose(t_matrix m);
t_matrix		inversion(t_matrix m);
t_matrix		view_transform(t_tuple from, t_tuple to, t_tuple up);
//tuple functions
t_tuple			point(double x, double y, double z);
t_tuple			vector(double x, double y, double z);
t_tuple			add(t_tuple a, t_tuple b);
t_tuple			sub(t_tuple a, t_tuple b);
t_tuple			harmard(t_tuple a, t_tuple b);
t_tuple			neg(t_tuple a);
t_tuple			multiply(t_tuple a, double b);
t_tuple			divide(t_tuple a, double b);
double			magnitude(t_tuple a);
t_tuple			normalize(t_tuple a);
double			dot(t_tuple a, t_tuple b);
t_tuple			cross(t_tuple a, t_tuple b);
t_tuple 		color(double r, double g, double b);
//ray functions
t_ray			init_ray(t_tuple origin, t_tuple direction);
t_tuple			position_at(t_ray ray, double t);
t_ray			transform(t_ray ray, t_matrix m);
//sphere functions
t_sphere		init_sphere(t_tuple	p, double r);
void			set_tranform(void *v, t_matrix m, int type);
t_tuple			normal_at(t_sphere s, t_tuple p);
//mlx functions
void			pixel_put(t_img *data, int x, int y, int color);
int				destroy(t_struct *fc);
void			even_init(t_struct *fc);
int				init_graphics(t_struct *mlx);
//intersection functions
t_intersection	*intersect(t_ray r1, t_object *o);
t_intersection	*intersect_sphere(t_ray r1, t_sphere *s, double teta);
t_intersection	*intersect_plane(t_ray r, t_plane *pl);
double			hit(t_intersection *inter);
t_tuple			reflect(t_tuple in, t_tuple normal);
//light functions
t_light			point_light(t_tuple position, t_tuple intensity, double brightness);
t_material		init_material(double ambient, double diffuse, double specular);
t_tuple			lighting(t_material m, t_light light, t_all *a, int shadow_in);
t_tuple			shade_hit(t_world *world, t_ray r, t_all *a);
//color functions
t_tuple 		to_color(unsigned int c);
unsigned int	to_int(t_tuple c);
//lst.c
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
//world_0.c
t_world			init_world(void);
void			add_light(t_world *world, t_light *light);
void			add_object(t_world *world, t_object *object);
t_all			prepare_compute(t_world *w, t_ray r);
//camera.c
t_camera		init_camera(t_tuple pos, t_tuple look_at, int degree);
t_ray			ray_for_pixel(t_camera *c, int x, int y);
void			render(t_camera *c, t_world *w, t_img *img, int uv);
//patterns.c
t_tuple			stripe_at(t_tuple a, t_tuple b, t_tuple point);
t_tuple			stripe_at_object(t_tuple a, t_tuple b, t_all *all, int i);

//debug functions
void			print_matrix(t_matrix m);    ///remove it
void 			printf_world(t_world *w);		///remove it

t_tuple	lighting_p(t_plane *p, t_light *l, t_all *a);
int	is_shadowed(t_world *world, t_tuple point, t_light	light);
t_light	point_light(t_tuple position, t_tuple intensity, double brightness);
t_material	init_material(double ambient, double diffuse, double specular);

//checkboard
t_tuple	uv_checker(t_all *all, t_tuple a, t_tuple b);

#endif
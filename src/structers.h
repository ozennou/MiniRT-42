/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:11:48 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/07 22:29:32 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTERS_H
# define STRUCTERS_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct s_matrix
{
	int		size;
	double	m[4][4];
}	t_matrix;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_adress
{
	void			*addr;
	struct s_adress	*next;
	struct s_adress	*last;
}	t_adress;

typedef struct s_struct
{
	void	*img;
	void	*mlx;
	void	*win;
}	t_struct;

typedef struct s_img
{
	void	*img;
	char	*bf;
	int		pxl_b;
	int		ln_b;
	int		endian;
}	t_img;

typedef struct s_object
{
	int		type;
	void	*object;
}	t_object;

typedef struct s_intersecion
{
	double		t;
	int			type;
	t_object	object;
}	t_intersection;

typedef struct s_light
{
	t_tuple		position;
	t_tuple		intensity;
	double		brightness;
}	t_light;

typedef struct s_material
{
	t_tuple	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_sphere
{
	t_tuple		p;
	double		r;
	t_matrix	transform;
	t_material	material;
}	t_sphere;

typedef struct s_all
{
	t_object	*object;
	double		t;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		over_point;
}	t_all;

typedef struct s_plane
{
	t_tuple		p;
	t_tuple		normal;
	t_matrix	transform;
	t_material	material;
}	t_plane;

typedef struct s_camera
{
	double	half_width;
	double	half_height;
	t_tuple	pos;	
	t_tuple	look_at;
	double	fov;
	double	pixel_size;
}	t_camera;

typedef struct s_cylinder
{
	t_tuple		origin;
	t_tuple		normal;
	double		radius;
	double		min;
	double		max;
	t_matrix	transform;
	t_material	material;
}	t_cylinder;

typedef struct s_cone
{
	t_tuple		origin;
	t_tuple		normal;
	double		radius;
	double		min;
	double		max;
	t_matrix	transform;
	t_material	material;
}	t_cone;

typedef struct s_ambient
{
	double		intensity;
	t_tuple		color;
}	t_ambient;

typedef struct s_world
{
	t_list		*objects;
	t_list		*lights;
	t_ambient	*ambient;
	t_camera	*camera;
}	t_world;

#endif
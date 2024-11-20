/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:32:14 by mozennou          #+#    #+#             */
/*   Updated: 2024/03/08 16:07:40 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	to_int(t_tuple c)
{
	unsigned int	res;

	res = 0;
	if (c.x < 0)
		c.x = 0;
	else if (c.x > 1)
		c.x = 1;
	if (c.y < 0)
		c.y = 0;
	else if (c.y > 1)
		c.y = 1;
	if (c.z < 0)
		c.z = 0;
	else if (c.z > 1)
		c.z = 1;
	res = ((int)(c.x * 255) << 16) | ((int)(c.y * 255) << 8) | (int)(c.z * 255);
	return (res);
}

t_tuple	to_color(unsigned int c)
{
	t_tuple	res;

	res.x = (c >> 16) & 0xFF;
	res.y = (c >> 8) & 0xFF;
	res.z = c & 0xFF;
	res.w = 0;
	return (res);
}

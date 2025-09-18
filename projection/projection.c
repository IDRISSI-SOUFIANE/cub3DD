/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbied <oelbied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:46:40 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/17 11:32:36 by oelbied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	tchec_ofset(int wallstripheightjplane,	float texturestep)
{
	float	texturey;
	int		off;

	texturey = 0.0;
	if (wallstripheightjplane > HEIGHT)
	{
		off = (wallstripheightjplane - HEIGHT) / 2;
		texturey = off * texturestep;
	}
	return (texturey);
}

int	calck_wall_top(int wallstripheightjplane)
{
	int	walltoppixel;

	walltoppixel = (HEIGHT / 2) - (wallstripheightjplane / 2);
	if (walltoppixel < 0)
		walltoppixel = 0;
	return (walltoppixel);
}

int	calck_wall_bottom(int wallstripheightjplane)
{
	int	wallbottompixel;

	wallbottompixel = (HEIGHT / 2) + (wallstripheightjplane / 2);
	if (wallbottompixel >= HEIGHT)
		wallbottompixel = HEIGHT - 1;
	return (wallbottompixel);
}

void	print_to_pixel(t_value *v)
{
	unsigned int	color;
	float			texturestep;
	float			texturey;
	int				texy;

	texturestep = (float)v->tex->height / (float)v->wallstripheightjplane;
	texturey = tchec_ofset(v->wallstripheightjplane, texturestep);
	while (*(v->y) <= v->wallbottompixel)
	{
		texy = (int)texturey;
		if (texy < 0)
			texy = 0;
		if (texy >= v->tex->height)
			texy = v->tex->height - 1;
		color = get_pixel_color(v->tex, v->texx, texy);
		my_mlx_pixel_put(v->data, *(v->i), *(v->y), color);
		texturey += texturestep;
		(*(v->y))++;
	}
}

void	project_wall(t_data *data)
{
	t_decstr	argmo;

	argmo.i = 0;
	while (argmo.i < NUM_RAYS)
	{
		argmo.wallstripheightjplane = calcul_hite_wall(data, &argmo.i);
		argmo.walltoppixel = calck_wall_top(argmo.wallstripheightjplane);
		argmo.wallbottompixel = calck_wall_bottom(argmo.wallstripheightjplane);
		argmo.tex = NULL;
		tchck_vertecal_presontal(&argmo.tex, data, &argmo.i);
		argmo.texx = tcheck_ofset(data, &argmo.i, argmo.tex);
		argmo.y = 0;
		print_ceil(data, &argmo.i, &argmo.y, argmo.walltoppixel);
		argmo.v = (t_value){data, argmo.wallstripheightjplane,
			&argmo.i, &argmo.y, argmo.wallbottompixel, argmo.texx, argmo.tex};
		print_to_pixel(&argmo.v);
		print_floor(data, &argmo.i, &argmo.y);
		argmo.i++;
	}
}

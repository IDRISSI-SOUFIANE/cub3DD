/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcster_prt_tow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:11:45 by oelbied           #+#    #+#             */
/*   Updated: 2025/09/18 22:46:38 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	tchck_vertecal_presontal(t_img **tex, t_data *data, int *i)
{
	if (data->rays[*i].was_hit_vertical)
	{
		if (data->rays[*i].is_ray_facing_left)
			*tex = &data->v_map.west_img;
		else
			*tex = &data->v_map.east_img;
	}
	else
	{
		if (data->rays[*i].is_ray_facing_up)
			*tex = &data->v_map.north_img;
		else
			*tex = &data->v_map.south_img;
	}
}

int	tcheck_ofset(t_data *data, int *i, t_img *tex)
{
	float	offset;
	float	hity;
	float	hitx;
	int		texx;

	if (data->rays[*i].was_hit_vertical)
	{
		hity = data->rays[*i].wallhity;
		offset = fmod(hity, TILE_SIZE);
		texx = (int)((offset / (float)TILE_SIZE) * tex->width);
	}
	else
	{
		hitx = data->rays[*i].wallhitx;
		offset = fmod(hitx, TILE_SIZE);
		texx = (int)((offset / (float)TILE_SIZE) * tex->width);
	}
	if (texx >= tex->width)
		texx = tex->width - 1;
	return (texx);
}

void	print_ceil(t_data *data, int *i, int *y, int walltoppixel)
{
	while (*y < walltoppixel)
		my_mlx_pixel_put(data, *i, (*y)++, data->v_map.n_ceil);
}

void	print_floor(t_data *data, int *i, int *y)
{
	while (*y < HEIGHT)
		my_mlx_pixel_put(data, *i, (*y)++, data->v_map.n_floor);
}

int	calcul_hite_wall(t_data *data, int *i)
{
	float	rayangle;
	float	rawdistance;
	float	correcteddistance;
	float	distprojplane;
	int		wallstripheightjplane;

	rayangle = data->rays[*i].rayangle;
	rawdistance = data->rays[*i].distance;
	correcteddistance = rawdistance
		* cosf(rayangle - data->player.rotationangle);
	distprojplane = (WIDTH / 2) / tanf(FOV_ANGLE / 2);
	wallstripheightjplane = (int)((TILE_SIZE / correcteddistance)
			* distprojplane);
	return (wallstripheightjplane);
}

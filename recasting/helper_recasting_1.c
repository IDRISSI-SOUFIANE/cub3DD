/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_recasting_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:27:22 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/18 22:43:33 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	choose_hit(t_ray *ray, t_hit horz, t_hit ver)
{
	if (horz.dist < ver.dist)
	{
		ray->distance = horz.dist;
		ray->was_hit_vertical = 0;
		ray->wallhitx = horz.x;
		ray->wallhity = horz.y;
	}
	else
	{
		ray->distance = ver.dist;
		ray->was_hit_vertical = 1;
		ray->wallhitx = ver.x;
		ray->wallhity = ver.y;
	}
}

t_ray_params	set_horz_params(t_data *data, t_ray *ray, float angle)
{
	t_ray_params	p;

	p.yintercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_down)
		p.yintercept += TILE_SIZE;
	p.xintercept = data->player.x
		+ (p.yintercept - data->player.y) / tan(angle);
	p.ystep = TILE_SIZE;
	if (ray->is_ray_facing_up)
		p.ystep *= -1;
	p.xstep = TILE_SIZE / tan(angle);
	if (ray->is_ray_facing_left && p.xstep > 0)
		p.xstep *= -1;
	if (ray->is_ray_facing_right && p.xstep < 0)
		p.xstep *= -1;
	return (p);
}

t_ray_params	set_ver_params(t_data *data, t_ray *ray, float angle)
{
	t_ray_params	p;

	p.xintercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_right)
		p.xintercept += TILE_SIZE;
	p.yintercept = data->player.y
		+ (p.xintercept - data->player.x) * tan(angle);
	p.xstep = TILE_SIZE;
	if (ray->is_ray_facing_left)
		p.xstep *= -1;
	p.ystep = TILE_SIZE * tan(angle);
	if (ray->is_ray_facing_up && p.ystep > 0)
		p.ystep *= -1;
	if (ray->is_ray_facing_down && p.ystep < 0)
		p.ystep *= -1;
	return (p);
}

void	get_horz_hit(t_data *data, t_ray *ray, t_ray_params p, t_hit *hit)
{
	float	nx;
	float	ny;

	nx = p.xintercept;
	ny = p.yintercept;
	if (ray->is_ray_facing_up)
		ny -= 0.002;
	while (nx >= 0 && nx <= (calculate_width(data->map) * TILE_SIZE)
		&& ny >= 0 && ny <= (calculate_height(data->map) * TILE_SIZE))
	{
		if (has_wall_at(data, nx, ny))
		{
			hit->x = nx;
			hit->y = ny;
			hit->dist = d_bt_points(data->player.x, data->player.y, nx, ny);
			return ;
		}
		nx += p.xstep;
		ny += p.ystep;
	}
}

void	get_ver_hit(t_data *data, t_ray *ray, t_ray_params p, t_hit *hit)
{
	float	nx;
	float	ny;

	nx = p.xintercept;
	ny = p.yintercept;
	if (ray->is_ray_facing_left)
		nx -= 0.002;
	while (nx >= 0 && nx <= (calculate_width(data->map) * TILE_SIZE)
		&& ny >= 0 && ny <= (calculate_height(data->map) * TILE_SIZE))
	{
		if (has_wall_at(data, nx, ny))
		{
			hit->x = nx;
			hit->y = ny;
			hit->dist = d_bt_points(data->player.x,
					data->player.y, nx, ny);
			return ;
		}
		nx += p.xstep;
		ny += p.ystep;
	}
}

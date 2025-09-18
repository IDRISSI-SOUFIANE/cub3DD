/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:44:23 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/18 22:41:09 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_hit(t_hit *hit)
{
	hit->dist = FLT_MAX;
	hit->x = 0;
	hit->y = 0;
}

void	set_ray_direction(t_ray *ray, float angle)
{
	ray->is_ray_facing_down = angle > 0 && angle < M_PI;
	ray->is_ray_facing_up = !ray->is_ray_facing_down;
	ray->is_ray_facing_right = angle < 0.5 * M_PI || angle > 1.5 * M_PI;
	ray->is_ray_facing_left = !ray->is_ray_facing_right;
}

int	cast_ray(t_data *data, int col, float angle)
{
	t_hit			horz;
	t_hit			ver;
	t_ray_params	h;
	t_ray_params	v;

	set_ray_direction(&data->rays[col], angle);
	init_hit(&horz);
	init_hit(&ver);
	h = set_horz_params(data, &data->rays[col], angle);
	v = set_ver_params(data, &data->rays[col], angle);
	get_horz_hit(data, &data->rays[col], h, &horz);
	get_ver_hit(data, &data->rays[col], v, &ver);
	data->rays[col].rayangle = angle;
	choose_hit(&data->rays[col], horz, ver);
	if (data->rays[col].distance == FLT_MAX)
		return (0);
	return (1);
}

void	cast_all_rays(t_data *data)
{
	int		i;
	float	angle;

	i = 0;
	angle = data->player.rotationangle - (FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		angle = normalize_angl(angle);
		cast_ray(data, i, angle);
		angle += FOV_ANGLE / NUM_RAYS;
		i++;
	}
}

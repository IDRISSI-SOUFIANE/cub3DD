/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_recasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:16:57 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/18 22:10:19 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	d_bt_points(float x1, float y1, float x2, float y2)
{
	float	dx;
	float	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrt((dx * dx) + (dy * dy)));
}

int	calculate_width(char **map)
{
	int	max_w;
	int	cur_w;
	int	i;

	max_w = 0;
	i = 0;
	while (map[i])
	{
		cur_w = 0;
		while (map[i][cur_w])
			cur_w++;
		if (cur_w > max_w)
			max_w = cur_w;
		i++;
	}
	return (max_w);
}

int	calculate_height(char **map)
{
	int	h;

	h = 0;
	while (map[h])
		h++;
	return (h);
}

float	normalize_angl(float angle)
{
	float	res;

	res = fmod(angle, 2 * M_PI);
	if (res < 0)
		res += (2 * M_PI);
	return (res);
}

int	has_wall_at(t_data *data, float x, float y)
{
	int	gx;
	int	gy;
	int	h;

	gx = floor(x / TILE_SIZE);
	gy = floor(y / TILE_SIZE);
	h = calculate_height(data->map);
	if (gy < 0 || gy >= h)
		return (1);
	if (gx < 0 || gx >= (int)ft_strlen(data->map[gy]))
		return (1);
	return (data->map[gy][gx] == '1');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:54:43 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/18 22:39:48 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	has_wall_at_1337(t_data *data, float x, float y)
{
	int	map_grid_index_x;
	int	map_grid_index_y;

	if (x < 0 || x > WIDTH * TILE_SIZE || y < 0 || y > HEIGHT * TILE_SIZE)
		return (1);
	map_grid_index_x = floor(x / TILE_SIZE);
	map_grid_index_y = floor(y / TILE_SIZE);
	if (data->map[map_grid_index_y][map_grid_index_x] == '1')
		return (1);
	return (0);
}

void	update_position(t_data *data, t_move *mv)
{
	if (mv->move_step != 0)
	{
		mv->new_x += cos(data->player.rotationangle) * mv->move_step;
		mv->new_y += sin(data->player.rotationangle) * mv->move_step;
	}
	if (mv->strafe_step != 0)
	{
		mv->new_x += cos(data->player.rotationangle + M_PI_2) * mv->strafe_step;
		mv->new_y += sin(data->player.rotationangle + M_PI_2) * mv->strafe_step;
	}
}

void	apply_collision(t_data *data, t_move *mv)
{
	int	margin;

	margin = mv->radius;
	if (!has_wall_at_1337(data, mv->new_x + margin, data->player.y)
		&& !has_wall_at_1337(data, mv->new_x - margin, data->player.y)
		&& !has_wall_at_1337(data, mv->new_x, data->player.y + margin)
		&& !has_wall_at_1337(data, mv->new_x, data->player.y - margin)
		&& !has_wall_at_1337(data, mv->new_x + margin, data->player.y + margin)
		&& !has_wall_at_1337(data, mv->new_x - margin, data->player.y + margin)
		&& !has_wall_at_1337(data, mv->new_x + margin, data->player.y - margin)
		&& !has_wall_at_1337(data, mv->new_x - margin, data->player.y - margin))
	{
		data->player.x = mv->new_x;
	}
	if (!has_wall_at_1337(data, data->player.x, mv->new_y + margin)
		&& !has_wall_at_1337(data, data->player.x, mv->new_y - margin)
		&& !has_wall_at_1337(data, data->player.x + margin, mv->new_y)
		&& !has_wall_at_1337(data, data->player.x - margin, mv->new_y)
		&& !has_wall_at_1337(data, data->player.x + margin, mv->new_y + margin)
		&& !has_wall_at_1337(data, data->player.x - margin, mv->new_y + margin)
		&& !has_wall_at_1337(data, data->player.x + margin, mv->new_y - margin)
		&& !has_wall_at_1337(data, data->player.x - margin, mv->new_y - margin))
	{
		data->player.y = mv->new_y;
	}
}

void	rotate_player(t_data *data)
{
	if (data->player.turndirection != 0)
	{
		data->player.rotationangle += data->player.turndirection
			* data->player.turnspeed;
		data->player.rotationangle = normalize_angl(data->player.rotationangle);
	}
}

void	move_player(t_data *data)
{
	t_move	mv;

	mv.move_step = data->player.walkdirection * data->player.walkspeed;
	mv.strafe_step = data->player.strafedirection * data->player.walkspeed;
	mv.new_x = data->player.x;
	mv.new_y = data->player.y;
	mv.radius = 15;
	rotate_player(data);
	update_position(data, &mv);
	apply_collision(data, &mv);
}

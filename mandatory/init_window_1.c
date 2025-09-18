/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbied <oelbied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:53:24 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/14 10:41:38 by oelbied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 13)
		data->player.walkdirection = 1;
	else if (keycode == 1)
		data->player.walkdirection = -1;
	else if (keycode == 0)
		data->player.strafedirection = -1;
	else if (keycode == 2)
		data->player.strafedirection = 1;
	else if (keycode == 124)
		data->player.turndirection = 1;
	else if (keycode == 123)
		data->player.turndirection = -1;
	else if (keycode == 53)
		(free_all(data), exit(0));
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 13 || keycode == 1)
		data->player.walkdirection = 0;
	else if (keycode == 0 || keycode == 2)
		data->player.strafedirection = 0;
	else if (keycode == 124 || keycode == 123)
		data->player.turndirection = 0;
	return (0);
}

int	close_window(t_data *data)
{
	if (data->wall.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->wall.img_ptr);
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_all(data);
	exit(0);
}

void	handle_event(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->win_ptr, 3, 1L << 1, key_release, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
}

void	cleanup(t_data *data)
{
	if (data->wall.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->wall.img_ptr);
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

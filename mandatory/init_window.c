/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:43:58 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/19 17:27:18 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	find_player(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->player.x = (j + 0.5f) * TILE_SIZE;
				data->player.y = (i + 0.5f) * TILE_SIZE;
				if (data->map[i][j] == 'N')
					data->player.rotationangle = 3 * M_PI / 2;
				else if (data->map[i][j] == 'S')
					data->player.rotationangle = M_PI / 2;
				else if (data->map[i][j] == 'E')
					data->player.rotationangle = 0;
				else if (data->map[i][j] == 'W')
					data->player.rotationangle = M_PI;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	init_struct(t_data *data)
{
	int	i;
	int	j;

	data->player.walkspeed = 3.5f;
	data->player.turnspeed = 5 * (M_PI / 180);
	i = 0;
	j = 0;
	find_player(data, i, j);
}

int	game_loop(t_data *data)
{
	move_player(data);
	cast_all_rays(data);
	project_wall(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.img_ptr, 0, 0);
	return (0);
}

int	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if ((WIDTH > 8192 || HEIGHT > 8192) || (WIDTH <= 0 || HEIGHT <= 0))
		return (ft_putstr_fd("Erro: window not correct\n", 2), 1337);
	if (!data->mlx_ptr)
		exit(1);
	init_struct(data);
	if (load_textures(data))
		(cleanup(data), exit(1));
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!data->win_ptr)
		return (cleanup(data),
			ft_putstr_fd("Erro: data->win_ptr\n", 2), 1337);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img.img_ptr)
		return (cleanup(data),
			ft_putstr_fd("Erro: data->win_ptr\n", 2), 1337);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	if (!data->img.addr)
		return (cleanup(data),
			ft_putstr_fd("Erro: data->img.addr\n", 2), 1337);
	handle_event(data);
	mlx_loop_hook(data->mlx_ptr, game_loop, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

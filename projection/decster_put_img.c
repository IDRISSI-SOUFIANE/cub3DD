/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decster_put_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbied <oelbied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:06:50 by oelbied           #+#    #+#             */
/*   Updated: 2025/09/17 11:15:26 by oelbied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned int	get_pixel_color(t_img *img, int x, int y)
{
	char	*pixel_addr;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	pixel_addr = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)pixel_addr);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	put_image(t_data *data)
{
	data->v_map.east_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->v_map.east, &data->v_map.east_img.width,
			&data->v_map.east_img.height);
	data->v_map.west_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->v_map.west,
			&data->v_map.west_img.width, &data->v_map.west_img.height);
	data->v_map.north_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->v_map.north, &data->v_map.north_img.width,
			&data->v_map.north_img.height);
	data->v_map.south_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->v_map.south, &data->v_map.south_img.width,
			&data->v_map.south_img.height);
	if (!data->v_map.north_img.img_ptr || !data->v_map.south_img.img_ptr
		|| !data->v_map.west_img.img_ptr || !data->v_map.east_img.img_ptr)
		return (ft_putstr_fd("load_textures: failed toopen texture file(s)\n",
				STDERR_FILENO), 1);
	return (0);
}

int	put_addr(t_data *data)
{
	data->v_map.east_img.addr = mlx_get_data_addr(data->v_map.east_img.img_ptr,
			&data->v_map.east_img.bpp, &data->v_map.east_img.line_len,
			&data->v_map.east_img.endian);
	data->v_map.west_img.addr = mlx_get_data_addr(data->v_map.west_img.img_ptr,
			&data->v_map.west_img.bpp, &data->v_map.west_img.line_len,
			&data->v_map.west_img.endian);
	data->v_map.north_img.addr
		= mlx_get_data_addr(data->v_map.north_img.img_ptr,
			&data->v_map.north_img.bpp, &data->v_map.north_img.line_len,
			&data->v_map.north_img.endian);
	data->v_map.south_img.addr
		= mlx_get_data_addr(data->v_map.south_img.img_ptr,
			&data->v_map.south_img.bpp, &data->v_map.south_img.line_len,
			&data->v_map.south_img.endian);
	if (!data->v_map.north_img.addr || !data->v_map.south_img.addr
		|| !data->v_map.west_img.addr || !data->v_map.east_img.addr)
	{
		ft_putstr_fd("load_textures: failed to get texture data address\n",
			STDERR_FILENO);
		return (1);
	}
	return (0);
}

int	load_textures(t_data *data)
{
	if (put_image(data))
		return (1);
	if (put_addr(data))
		return (1);
	return (0);
}

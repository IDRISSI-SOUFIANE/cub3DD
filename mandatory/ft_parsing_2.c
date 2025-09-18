/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:35:51 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/18 20:02:48 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_number(char *color, char *path, t_data *data)
{
	char	**res;
	int		r;
	int		g;
	int		b;

	res = NULL;
	res = ft_split(path, ", ");
	if (NULL == res)
		return (ft_putstr_fd("Error: invalid number\n", 2), 1337);
	if (check_res(res))
		return (free_2d_array(res),
			ft_putstr_fd("Error: invalid number\n", 2), 1337);
	r = ft_atoi(res[0]);
	g = ft_atoi(res[1]);
	b = ft_atoi(res[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (free_2d_array(res),
			ft_putstr_fd("Error: invalid number\n", 2), 1337);
	if (!ft_strcmp(color, "F "))
		data->v_map.n_floor = (r << 16 | g << 8 | b << 0);
	else if (!ft_strcmp(color, "C "))
		data->v_map.n_ceil = (r << 16 | g << 8 | b << 0);
	return (free_2d_array(res), 0);
}

int	check_comma(char *path)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (path[i])
	{
		if (path[i] == ',')
			count++;
		if (path[i] == ',' && path[i + 1] == ',')
			return (ft_putstr_fd("Error: invalid comma\n", 2), 1337);
		i++;
	}
	if (count != 2)
		return (ft_putstr_fd("Error: invalid comma\n", 2), 1337);
	return (0);
}

int	check_v_color(char *color, char *path, t_data *data)
{
	if (!ft_strcmp(color, "F ") || !ft_strcmp(color, "C "))
	{
		if (check_comma(path) || check_number(color, path, data))
			return (1337);
	}
	return (0);
}

int	check_v_path(char *str, char *path)
{
	int	fd;

	if (!ft_strcmp(str, "NO ") || !ft_strcmp(str, "SO ")
		|| !ft_strcmp(str, "WE ") || !ft_strcmp(str, "EA "))
	{
		fd = open(path, O_RDONLY);
		if ((fd < 0))
			return (ft_putstr_fd("Error: Invalid Path\n", 2), close(fd), 1337);
		close(fd);
	}
	return (0);
}

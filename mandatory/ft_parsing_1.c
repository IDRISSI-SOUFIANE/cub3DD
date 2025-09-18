/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:31:22 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/18 20:02:27 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	assign_and_check_attribute(t_data *data, char *path, int *count)
{
	if (!ft_strcmp(data->v_map.str, "NO ") && !data->v_map.north)
		data->v_map.north = path;
	else if (!ft_strcmp(data->v_map.str, "SO ") && !data->v_map.south)
		data->v_map.south = path;
	else if (!ft_strcmp(data->v_map.str, "WE ") && !data->v_map.west)
		data->v_map.west = path;
	else if (!ft_strcmp(data->v_map.str, "EA ") && !data->v_map.east)
		data->v_map.east = path;
	else if (!ft_strcmp(data->v_map.color, "F ") && !data->v_map.floor)
		data->v_map.floor = path;
	else if (!ft_strcmp(data->v_map.color, "C ") && !data->v_map.ceil)
		data->v_map.ceil = path;
	else
		return (0);
	(*count)++;
	return (1);
}

static char	*get_and_validate_path(char *line)
{
	char	*path;

	path = ft_substr(line, index_start(line), index_end(line));
	if (NULL == path)
	{
		ft_putstr_fd("Error: path is NULL\n", 2);
		return (NULL);
	}
	if (!ft_strcmp(path, "\0"))
	{
		ft_putstr_fd("Error: path is not correct\n", 2);
		free(path);
		return (NULL);
	}
	return (path);
}

int	check_dublicate(t_data *data, char *line, int *count)
{
	char	*path;
	int		assigned;

	if (!ft_strcmp(line, "\0"))
		return (*count);
	if (ft_strcmp(data->v_map.str, "NO ") && ft_strcmp(data->v_map.str, "SO ")
		&& ft_strcmp(data->v_map.str, "WE ")
		&& ft_strcmp(data->v_map.str, "EA ")
		&& ft_strcmp(data->v_map.color, "F ")
		&& ft_strcmp(data->v_map.color, "C "))
		return (ft_putstr_fd("Error: invalid arg\n", 2), 1337);
	path = get_and_validate_path(line);
	if (!path)
		return (ft_putstr_fd("Error: invalid Path\n", 2), 1337);
	assigned = assign_and_check_attribute(data, path, count);
	if (!assigned)
	{
		ft_putstr_fd("invalid arg\n", 2);
		return (free(path), 1337);
	}
	if (check_v_path(data->v_map.str, path)
		|| check_v_color(data->v_map.color, path, data))
		return (1337);
	return (*count);
}

int	check_direction(t_data *data, char *line, int *count)
{
	if (check_dublicate(data, line, count) == 1337)
		return (1337);
	return (*(count));
}

int	check_line(t_data *data, char *line, int *count)
{
	int		check;
	char	*new_line;

	new_line = ft_strtrim(line, " ");
	data->v_map.str = get_word(new_line, 3);
	data->v_map.color = get_word(new_line, 2);
	if ((NULL == data->v_map.str) || (NULL == data->v_map.color))
		return (ft_putstr_fd("Error: invalid args\n", 2), 1337);
	check = check_direction(data, new_line, count);
	free(new_line);
	if (check == 1337)
		return (free(data->v_map.str), free(data->v_map.color), 1337);
	return (free(data->v_map.str), free(data->v_map.color), *(count));
}

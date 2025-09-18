/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:43:53 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/18 21:23:12 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_first_part(int fd, char *line, int count, t_data *data)
{
	int		n_count;
	char	*new_line;

	n_count = 0;
	fd = open("map/map.cub", O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error: fd error\n", STDERR_FILENO), 1337);
	line = get_next_line(fd);
	while ((line != NULL) && n_count != 6)
	{
		if (ft_strcmp(line, "\n"))
		{
			new_line = ft_strtrim(line, "\n");
			n_count = check_line(data, new_line, &count);
			if (n_count == 1337)
				return (free(line), free(new_line), 1337);
			(free(line), free(new_line));
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	if (n_count != 6)
		return (free(line), 1);
	return (close(fd), free(line), 0);
}

int	ft_parsing(char *map, t_data *data)
{
	int		fd;
	int		count;
	int		fd_map;
	char	*line;

	line = NULL;
	fd_map = open(map, O_RDONLY);
	if (fd_map < 0)
		return (ft_putstr_fd("Error: fd not valid\n", 2), 1337);
	close (fd_map);
	fd = 0;
	count = 0;
	if (check_extention(map))
		return (1);
	if (check_first_part(fd, line, count, data))
	{
		return (free_v_map(&data->v_map), free(data->v_map._join_map_lines), 1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	**string;

	(void)ac;
	ft_memset(&data, 0, sizeof(t_data));
	string = men();
	if ((!av[1]) || ft_parsing(av[1], &data))
		return (free_2d_array(string), 1);
	if (string == NULL)
	{
		return (ft_putstr_fd("ERROR: map not valid!\n", 2),
			free_2d_array(string), 1);
	}
	data.map = check_map(string);
	if (NULL == data.map)
		return (ft_putstr_fd("Error: check map\n", 2),
			free_all(&data), 1337);
	if (init_window(&data))
		return (free_all(&data), ft_putstr_fd("ERROR: init_window!\n", 2), 1);
	free_all(&data);
	return (0);
}

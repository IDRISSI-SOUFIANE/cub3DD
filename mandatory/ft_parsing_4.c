/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:28:59 by sidrissi          #+#    #+#             */
/*   Updated: 2025/09/18 18:32:51 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int	check_map_line_2(char *line, int fd)
// {
// 	char	*_line_;

// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		_line_ = ft_strtrim_end(line, " ");
// 		if (ft_strcmp(_line_, "\n"))
// 			return (free(line), free(_line_), line = NULL, _line_ = NULL, 1337);
// 		free(line);
// 		free(_line_);
// 		line = get_next_line(fd);
// 	}
// 	return (0);
// }

// int	check_map_line(char *line, int fd, int *flag)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_strcmp(line, "\n"))
// 	{
// 		*flag = 1;
// 		while (line[i] == ' ')
// 			i++;
// 		while (line[i])
// 		{
// 			if (ft_0_1_map(line[i]) && line[i] != ' '
// 				&& line[i] != '\n' && p_player(line[i]))
// 				return (ft_putstr_fd("check_map_line \n", 2), 1337);
// 			i++;
// 		}
// 	}
// 	else if (*flag == 1)
// 	{
// 		if (check_map_line_2(line, fd))
// 			return (1337);
// 	}
// 	return (0);
// }

// static char	*process_remaining_lines(char *temp, int fd, int *flag)
// {
// 	char	*line;
// 	char	*_line_;
// 	char	*res;

// 	res = NULL;
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		if (check_map_line(line, fd, flag))
// 			return (free(line), free(temp), NULL);
// 		if (!ft_strcmp(line, "\n"))
// 		{
// 			free(line);
// 			break ;
// 		}
// 		_line_ = ft_strtrim_end(line, " ");
// 		res = ft_strjoin(temp, _line_);
// 		(free(line), free(_line_));
// 		if (!res)
// 			return (free(temp), NULL);
// 		free(temp);
// 		temp = res;
// 		line = get_next_line(fd);
// 	}
// 	return (temp);
// }

// int	store_map(t_data *data, char *line, int fd, int *flag)
// {
// 	char	*_line_;
// 	char	*temp;

// 	temp = NULL;
// 	while (line && !ft_strcmp(line, "\n"))
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	if (NULL == line)
// 		return (1337);
// 	if (check_map_line(line, fd, flag))
// 		return (free(line), 1337);
// 	_line_ = ft_strtrim_end(line, " ");
// 	temp = ft_strjoin(temp, _line_);
// 	(free(_line_), free(line));
// 	if (!temp)
// 		return (1337);
// 	temp = process_remaining_lines(temp, fd, flag);
// 	if (!temp)
// 		return (1337);
// 	data->v_map._join_map_lines = temp;
// 	return (close(fd), 0);
// }

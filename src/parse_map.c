/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:58:54 by vnazioze          #+#    #+#             */
/*   Updated: 2023/02/08 02:22:44 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	validate_map_boundaries(int line, int column, t_data *data)
{
	char	**map;

	map = data->map.map;
	if (ft_strchr("0NSWE", map[line][column]) && (
		map[line][column + 1] == '\0' || map[line + 1][column + 1] == '\0' || \
		map[line][column - 1] == '\0' || map[line + 1][column - 1] == '\0' || \
		map[line + 1][column] == '\0' || map[line - 1][column + 1] == '\0' || \
		map[line - 1][column] == '\0' || map[line - 1][column - 1] == '\0' || \
		map[line][column + 1] == ' ' || map[line + 1][column + 1] == ' ' || \
		map[line][column - 1] == ' ' || map[line + 1][column - 1] == ' ' || \
		map[line + 1][column] == ' ' || map[line - 1][column + 1] == ' ' || \
		map[line - 1][column] == ' ' || map[line - 1][column - 1] == ' ' )
		)
		error_message(20, "Invalid map: not surrounded by walls", data);
}

static void	get_player_angle(int line, int column, t_data *data)
{
	if (ft_strchr("NSWE", data->map.map[line][column]))
	{
		data->player.count++;
		data->player.line = line * SPRITE_LEN + SPRITE_LEN / 2;
		data->player.column = column * SPRITE_LEN + SPRITE_LEN / 2;
		if (data->map.map[line][column] == 'E')
			data->player.angle = (PI / 2) * 0;
		if (data->map.map[line][column] == 'N')
			data->player.angle = (PI / 2) * 1;
		if (data->map.map[line][column] == 'W')
			data->player.angle = (PI / 2) * 2;
		if (data->map.map[line][column] == 'S')
			data->player.angle = (PI / 2) * 3;
		printf("player line (line): %02d\n", line);
		printf("player column (column): %02d\n", column);
		printf("- player.line: %02f\n", data->player.line);
		printf("- player.column: %02f\n", data->player.column);
	}
}

static void	get_map(t_data *data)
{
	if (data->map.start_line == 0)
		error_message(19, "Invalid map: missing map", data);
	data->map.map = &(data->map.lines[data->map.start_line - 1]);
}

void	parse_map(t_data *data)
{
	int	line;
	int	column;

	get_map(data);
	data->player.count = 0;
	line = -1;
	while (data->map.map[++line] != NULL)
	{
		column = -1;
		while (data->map.map[line][++column] != '\0')
		{
			validate_map_boundaries(line, column, data);
			get_player_angle(line, column, data);
		}
		// TALVEZ APAGUE PQ N HA UTILIZADE
		// if (column > data->map.max_column)
		// 	data->map.max_column = column;
	}
	if (data->player.count > 1)
		error_message(21, "Invalid player: too many", data);
	if (data->player.count < 1)
		error_message(22, "Invalid player: not enough", data);
	// data->map.max_line = line;
	// printf("quantity line (line): %02d\n", line);
	// printf("quantity column (column): %02d\n", column);
	// printf("max column: %02d\n", data->map.max_column);
}

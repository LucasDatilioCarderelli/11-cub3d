/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:56:12 by ldatilio          #+#    #+#             */
/*   Updated: 2023/02/16 00:03:43 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void		make_image(t_data *data);
void		make_vertical_line(
				t_data *data, int dist, double ix, t_img_data *img);
static void	put_vertical_line(t_data *data, t_img_data *img);
static void	my_img_pixel_put(t_img_data *img, int x, int y, int color);
static int	my_img_pixel_get(t_img_data *img, int x, int y);

void	make_image(t_data *data)
{
	get_fps(data);
	data->img.game = malloc(sizeof(t_img));
	data->img.game->new_img = mlx_new_image(\
		data->mlx, WINDOW_SIZE, WINDOW_SIZE \
		);
	data->img.game->address = mlx_get_data_addr(\
		data->img.game->new_img, &data->img.game->bits_per_pixel, \
		&data->img.game->line_length, &data->img.game->endian \
		);
	data->ra = data->player.angle + (PI / 180 * SPRITE_SIZE / 2);
	data->ray_num = 0;
	while (data->ray_num < SPRITE_SIZE)
	{
		raycast(data, data->ra);
		data->ra -= PI / 180;
		data->ray_num++;
	}
	mlx_put_image_to_window(
		data->mlx, data->win, data->img.game->new_img, 0, 0
		);
	mlx_destroy_image(data->mlx, data->img.game->new_img);
	free(data->img.game);
}

/*
rc.y_ceil	: y_ceil
rc.line_height	: line_heighteight
rc.y_tex_step	: y_tex_step
rc.y_tex_off	: y_tex_offset
rc.line_offset	: line_offsetffset
rc.y_max	: y_line_max
rc.x_tex		: x_tex
ix			: x_intersection
*/


void	make_vertical_line(t_data *data, int dist, double ix, t_img_data *img)
{
	data->rc.y_ceil = 0;
	if (dist == 0)
		dist = 1;
	data->rc.line_height = (SPRITE_SIZE * WINDOW_SIZE) / dist;
	data->rc.y_tex_step = SPRITE_SIZE / (float)data->rc.line_height;
	data->rc.y_tex_offset = 0;
	if (data->rc.line_height > WINDOW_SIZE)
	{
		data->rc.y_tex_offset = (data->rc.line_height - WINDOW_SIZE) / 2.0;
		data->rc.line_height = WINDOW_SIZE;
	}
	data->rc.line_offset = WINDOW_SIZE / 2 - data->rc.line_height / 2;
	data->rc.y_max = data->rc.line_offset + data->rc.line_height;
	data->rc.x_tex = (int)(ix) % SPRITE_SIZE;
	if (img == data->img.so || img == data->img.we)
		data->rc.x_tex -= SPRITE_SIZE - 1;
	data->rc.y_tex = data->rc.y_tex_offset * data->rc.y_tex_step;
	put_vertical_line(data, img);
}

static void	put_vertical_line(t_data *data, t_img_data *img)
{
	while (data->rc.y_ceil <= data->rc.line_offset)
	{
		data->rc.x = (data->ray_num * SPRITE_SCALE);
		while (data->rc.x < (data->ray_num * SPRITE_SCALE) + SPRITE_SCALE)
			my_img_pixel_put(data->img.game, data->rc.x++, data->rc.y_ceil, \
			data->map.color.ceil);
		data->rc.y_ceil++;
	}
	while (data->rc.line_offset <= data->rc.y_max)
	{
		data->rc.x = (data->ray_num * SPRITE_SCALE);
		while (data->rc.x < (data->ray_num * SPRITE_SCALE) + SPRITE_SCALE)
			my_img_pixel_put(data->img.game, data->rc.x++, data->rc.line_offset, \
			my_img_pixel_get(img, (int)data->rc.x_tex, (int)data->rc.y_tex));
		data->rc.line_offset++;
		data->rc.y_tex += data->rc.y_tex_step;
	}
	while (data->rc.y_max <= WINDOW_SIZE)
	{
		data->rc.x = (data->ray_num * SPRITE_SCALE);
		while (data->rc.x < (data->ray_num * SPRITE_SCALE) + SPRITE_SCALE)
			my_img_pixel_put(data->img.game, data->rc.x++, data->rc.y_max, \
			data->map.color.floor);
		data->rc.y_max++;
	}
}

static void	my_img_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*byte;

	byte = img->address + ((y * img->line_length)
			+ (x * img->bits_per_pixel / SPRITE_SCALE));
	*(unsigned int *)byte = color;
}

static int	my_img_pixel_get(t_img_data *img, int x, int y)
{
	char	*byte;

	byte = img->address + ((y * img->line_length)
			+ (abs(x * img->bits_per_pixel / SPRITE_SCALE)));
	return (*(unsigned int *)byte);
}

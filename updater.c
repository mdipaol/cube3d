/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:29:49 by alegreci          #+#    #+#             */
/*   Updated: 2023/06/30 16:08:11 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* int	floor_darker(int color, int y)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	if (y < 1)
		return (color);

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	color = (r << 16) | (g << 8) | b;
	return (color);
} */

void my_mlx_pixel_put(t_img *screen, int x, int y, unsigned int color)
{
	char *dst;

	dst = screen->addr + (y * screen->line_length + x * (screen->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y <= HEIGHT / 2)
				my_mlx_pixel_put(&data->screen, x, y, data->ceiling);
			else
				my_mlx_pixel_put(&data->screen, x, y, data->floor);
			x++;
		}
		y++;
	}
}

int	updater(t_data *data)
{
	draw_background(data);
	raycaster(data);
	minimap_manager(data);
	animation_manager(data);
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img, 0, 0);
	if (data->p > 0)
		mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

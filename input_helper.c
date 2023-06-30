/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:45:18 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/30 14:47:01 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_esc_key(int keycode, t_data *data)
{
	if (keycode == P_KEY)
	{
		data->p *= -1;
		if (data->p < 0)
			mlx_mouse_show(data->mlx, data->win);
		else
			mlx_mouse_hide(data->mlx, data->win);
	}
	if (keycode == ESC)
		super_exit(data);
}
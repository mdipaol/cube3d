/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:25:33 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/16 17:13:02 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_all_map(char **all_map)
{
	int	i;

	i = 0;
	while (all_map[i])
	{
		free(all_map[i]);
		i++;
	}
	free(all_map[i]);
}

int	super_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}
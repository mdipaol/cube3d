/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:22:38 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/30 20:24:00 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_nord_path(t_data *data, char **all_map)
{
	int	i;
	int	j;

	i = 0;
	while (all_map[i])
	{
		j = 0;
		while (all_map[i][j])
		{
			if (all_map[i][j] == 'N' && all_map[i][j + 1] == 'O')
			{
				data->path_text[0] = texture_cleaner(all_map[i]);
				return ;
			}
			j++;
		}
		i++;
	}
	data->map_err = 1;
}

void	save_south_path(t_data *data, char **all_map)
{
	int	i;
	int	j;

	i = 0;
	while (all_map[i])
	{
		j = 0;
		while (all_map[i][j])
		{
			if (all_map[i][j] == 'S' && all_map[i][j + 1] == 'O')
			{
				data->path_text[1] = texture_cleaner(all_map[i]);
				return ;
			}
			j++;
		}
		i++;
	}
	data->map_err = 1;
}

void	save_west_path(t_data *data, char **all_map)
{
	int	i;
	int	j;

	i = 0;
	while (all_map[i])
	{
		j = 0;
		while (all_map[i][j])
		{
			if (all_map[i][j] == 'W' && all_map[i][j + 1] == 'E')
			{
				data->path_text[2] = texture_cleaner(all_map[i]);
				return ;
			}
			j++;
		}
		i++;
	}
	data->map_err = 1;
}

void	save_east_path(t_data *data, char **all_map)
{
	int	i;
	int	j;

	i = 0;
	while (all_map[i])
	{
		j = 0;
		while (all_map[i][j])
		{
			if (all_map[i][j] == 'E' && all_map[i][j + 1] == 'A')
			{
				data->path_text[3] = texture_cleaner(all_map[i]);
				return ;
			}
			j++;
		}
		i++;
	}
	data->map_err = 1;
}

void	save_path_text(t_data *data, char **all_map)
{
	data->path_text = malloc(sizeof(char *) * 5);
	data->path_text[4] = NULL;
	save_nord_path(data, all_map);
	save_south_path(data, all_map);
	save_west_path(data, all_map);
	save_east_path(data, all_map);
}

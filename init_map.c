/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:58:29 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/07/03 12:02:38 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	counter_all_mapfile(char *path)
{
	char	*s;
	int		fd;
	int		i;

	i = 1;
	fd = open(path, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
		i++;
	}
	i = i - 1;
	close(fd);
	free(s);
	return (i);
}

int	counter_map(char **all_map, int i)
{
	int	count;

	count = 0;
	while (all_map[i])
	{
		count++;
		i++;
	}
	return (count);
}

void	save_map_helper(t_data *data, char **all_map, int i)
{
	int	len;
	int	j;

	j = 0;
	len = counter_map(all_map, i);
	data->map = malloc(sizeof(char *) * (len + 1));
	while (j < len)
	{
		data->map[j] = ft_strdup(all_map[i]);
		i++;
		j++;
	}
	data->map[j] = NULL;
}

void	save_map(t_data *data, char **all_map)
{
	int	i;
	int	j;

	i = 0;
	while (all_map[i])
	{
		j = 0;
		while (all_map[i][j])
		{
			if (all_map[i][j] == '1' && all_map[i][j + 1] == '1' &&
				!ft_strchr(all_map[i], ',') && !ft_strchr(all_map[i], '/'))
			{
				save_map_helper(data, all_map, i);
				return ;
			}
			j++;
		}
		i++;
	}
	write(1, "Error\n", 7);
	ft_free_all_map(all_map);
	free(all_map);
	exit (1);
}

int	map_conversion(t_data *data, char *path)
{
	char	**all_map;
	int		i;
	int		fd;
	int		len;

	i = 0;
	data->map_err = 0;
	len = counter_all_mapfile(path);
	if (!len)
	{
		write(2, "Error: can't access file map\n", 29);
		return (1);
	}
	all_map = malloc(sizeof(char *) * (len + 1));
	fd = open(path, O_RDONLY);
	while (i < len)
	{
		all_map[i] = get_next_line(fd);
		i++;
	}
	all_map[i] = NULL;
	map_conversion_helper(data, all_map, fd);
	return (cam_init(data));
}

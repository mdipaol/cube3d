/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:17:59 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/18 19:02:35 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arg(char **str)
{
	int	i;

	i = 0;
	while (str[1][i])
	{
		if (str[1][i] == '.' && str[1][i + 1] == 'c' && \
		str[1][i + 2] == 'u' && str[1][i + 3] == 'b' && str[1][i + 4] == '\0')
			return (0);
		i++;
	}
	return (1);
}

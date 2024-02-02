/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:31:47 by jealves-          #+#    #+#             */
/*   Updated: 2024/02/02 20:34:49 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**convert_lst_to_char(t_list *lst)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (!str)
		error_msg("Memory allocation");
	while (lst)
	{
		str[i] = ft_strdup(lst->content);
		if (!str[i])
			exit(EXIT_FAILURE);
		i++;
		lst = lst->next;
	}
	return (str);
}

bool	is_map_char(char c)
{
	if (c != ' ' && c != '\n')
		return (true);
	return (false);
}

t_coord	*build_coord(double y, double x)
{
	t_coord	*coord;

	coord = ft_calloc(sizeof(t_coord), 1);
	if (!coord)
		error_msg("Memory allocation - coord");
	coord->x = x;
	coord->y = y;
	return (coord);
}

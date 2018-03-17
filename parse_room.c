/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:43:09 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/28 13:43:10 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					check_rooms(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
	{
		ft_arr_free(str);
		return (-1);
	}
	if (str[0][0] == 'L')
	{
		ft_arr_free(str);
		return (0);
	}
	if (str[3] != NULL)
	{
		ft_arr_free(str);
		return (0);
	}
	ft_arr_free(str);
	return (ROOMS);
}

int					check_room_name(char *name, int parse)
{
	if (parse == START || parse == END)
		return (1);
	if (name[0] == '#')
		return (0);
	if (name[0] == 'L')
		ft_exit("Wrong NAME");
	return (2);
}

int					return_something(char *line, int parse)
{
	if (parse == START || parse == END)
	{
		if (check_rooms(ft_strsplit(line, ' ')) != ROOMS
				|| (check_room_name(line, 0)) != 2)
			return (-1);
	}
	return (1);
}

int					parse_room(t_lem_in *lem, char *str, int parse)
{
	char *line;

	if ((check_room_name(str, parse)) != 0)
	{
		if (parse == START || parse == END)
		{
			if ((line = ignor_comment(lem)))
			{
				if (return_something(line, parse) == -1)
					return (-1);
				parse_hash(lem, ft_strsplit(line, ' '), parse);
				ft_strdel(&(line));
			}
		}
		else
		{
			if (check_rooms(ft_strsplit(str, ' ')) != ROOMS)
				return (-1);
			parse_rooms(lem, ft_strsplit(str, ' '));
		}
	}
	return (10);
}

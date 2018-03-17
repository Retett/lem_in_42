/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lem_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:52:04 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/19 13:52:05 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				parse_hash_corect(char *line, t_lem_in *lem)
{
	if (ft_strequ(line, START_STR))
		parse_room(lem, line, START);
	if (ft_strequ(line, END_STR))
		parse_room(lem, line, END);
}

static int			parse_argument(char *line)
{
	int i;
	int space;

	i = 0;
	space = 0;
	while (line[i++] != '\0')
	{
		if (line[0] == '#')
			return (HASH);
		if (line[i] == '-')
			return (LINKS);
		if (line[i] == ' ')
			space++;
	}
	if (space == 2)
		return (check_rooms(ft_strsplit(line, ' ')));
	return (STOP_IT);
}

int					corect_data(t_lem_in *lem, int parse)
{
	if (parse == -1)
		return (STOP_IT);
	else if (lem->room_flag == 1 && lem->link_flag == 1)
		return (STOP_IT);
	return (1);
}

void				add_line_to_line(t_lem_in *lem, char *line)
{
	if (!ft_strequ(line, "##start") &&
		!ft_strequ(line, "##end") && (!ft_strnequ(line, "###", 3)))
	{
		if (ft_strnequ(line, "##", 2))
			return ;
	}
	if (ft_strlen(lem->str) != 0)
		lem->str = ft_next(ft_next(lem->str, "\n"), line);
	else
		lem->str = ft_next(lem->str, line);
}

void				parse_lem_data(t_lem_in *lem)
{
	char	*line;
	int		parse;

	parse_ants(lem);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) == 0)
			break ;
		else if ((parse = parse_argument(line)) > 0)
		{
			if (parse == ROOMS)
				parse = parse_room(lem, line, parse);
			else if (parse == LINKS)
				if ((parse = check_link(lem, ft_strsplit(line, '-'))) == LINKS)
					parse_link(lem, line);
		}
		if (corect_data(lem, parse) == STOP_IT)
			break ;
		add_line_to_line(lem, line);
		if (line[0] == '#')
			parse_hash_corect(line, lem);
		ft_strdel(&(line));
	}
	ft_strdel(&(line));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:26:51 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/28 13:26:52 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		number_of_ants(char *line, t_lem_in *lem)
{
	int i;

	i = 0;
	while (*line == '0')
		line++;
	while (line[i])
	{
		if (line[i] == '-' || line[i] == '+')
		{
			if (line[i] == '-')
				ft_exit("ANts farm, work wrong");
			i++;
		}
		if (line[i] < '0' || line[i] > '9')
			ft_exit("No ants 1!!!");
		if (i > 10)
			ft_exit("NOOOO my farm");
		i++;
	}
	lem->ants = ft_atoi(line);
	if (lem->ants > MAX_INT ||
		lem->ants < MIN_INT ||
		lem->ants <= 0)
		ft_exit("No ants 2!!!");
}

static char		*ignor_comment_v2(t_lem_in *lem)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] != '#' || (ft_strequ(line, "##start")
			|| ft_strequ(line, "##end")))
		{
			add_line_to_line(lem, line);
			break ;
		}
		add_line_to_line(lem, line);
		free(line);
	}
	if (ret == -1)
		return (NULL);
	return (line);
}

void			parse_ants(t_lem_in *lem)
{
	char *line;

	if ((line = ignor_comment_v2(lem)))
	{
		if (ft_strlen(line) == 0)
			ft_exit("error ants");
		number_of_ants(line, lem);
		ft_strdel(&(line));
	}
	else
		ft_exit("error ants");
}

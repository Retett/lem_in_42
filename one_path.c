/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:07:30 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/03/05 16:07:31 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			go_ants_izi_road(t_lem_in *lem)
{
	int i;

	i = 1;
	while (i <= lem->ants)
	{
		printf("L%d-%s ", i, lem->end->name);
		i++;
	}
	printf("\n");
}

int					len_path(t_lem_in *lem)
{
	t_path *tmp;

	tmp = lem->path;
	while (tmp)
	{
		if (tmp->road == 1)
		{
			go_ants_izi_road(lem);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

char				*ignor_comment(t_lem_in *lem)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] != '#' || (ft_strequ(line, "##start")
			&& ft_strequ(line, "##end")))
		{
			add_line_to_line(lem, line);
			break ;
		}
		if ((!ft_strequ(line, "##start")
			&& !ft_strequ(line, "##end")))
			add_line_to_line(lem, line);
		free(line);
	}
	if (ret == -1)
		return (NULL);
	return (line);
}

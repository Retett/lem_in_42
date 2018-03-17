/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:24:03 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/28 13:24:04 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				check_link(t_lem_in *lem, char **str)
{
	t_room	*tmp;
	int		i;

	tmp = lem->room;
	i = 0;
	while (tmp)
	{
		if (ft_strequ(tmp->name, str[0]))
			i++;
		if (ft_strequ(tmp->name, str[1]))
			i++;
		tmp = tmp->next;
	}
	if (ft_strequ(str[0], str[1]))
		return (STOP_IT);
	ft_arr_free(str);
	if (i == 2)
		return (LINKS);
	return (STOP_IT);
}

static void		parse_links_function(t_lem_in *lem, char **str)
{
	t_room *tmp;
	t_room *tmp_2;

	tmp = lem->room;
	tmp_2 = lem->room;
	while (ft_strstr(tmp->name, str[0]) == 0 && tmp)
		tmp = tmp->next;
	while (ft_strstr(tmp_2->name, str[1]) == 0 && tmp_2)
		tmp_2 = tmp_2->next;
	ft_push_links(tmp, tmp_2);
	ft_push_links(tmp_2, tmp);
}

void			parse_link(t_lem_in *lem, char *line)
{
	char **split;

	lem->room_flag = 0;
	lem->link_flag = 1;
	if ((split = ft_strsplit(line, '-')) != NULL)
		parse_links_function(lem, split);
	ft_arr_free(split);
}

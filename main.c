/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:51:51 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/19 13:51:52 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	struc_init(t_lem_in *lem)
{
	lem->room = NULL;
	lem->ants = 0;
	lem->path = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->room_flag = 0;
	lem->link_flag = 0;
	CHECK(lem->str = (char*)ft_memalloc(sizeof(char)));
}

int			main(int ac, char **av)
{
	t_lem_in *lem;

	CHECK(lem = (t_lem_in*)ft_memalloc(sizeof(t_lem_in) * 1));
	struc_init(lem);
	parse_lem_data(lem);
	if (lem->start == NULL || lem->end == NULL)
		ft_exit("Error map 1");
	search_length(lem);
	search_short_path(lem);
	if ((lem->path) == NULL)
		ft_exit("Wrong map");
	path_count(lem->path);
	free_all_unusing(lem);
	ft_printf("%s\n\n", lem->str);
	move_ants(lem);
	debug_mod_activated(lem, ac, av);
	return (0);
}

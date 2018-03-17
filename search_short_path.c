/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_short_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:51:30 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/26 13:51:32 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					path_count(t_path *lem)
{
	t_path *tmp;
	t_mark *tmp_2;

	tmp = lem;
	while (tmp)
	{
		tmp_2 = tmp->room;
		while (tmp_2)
		{
			tmp->road++;
			tmp_2 = tmp_2->next;
		}
		tmp = tmp->next;
	}
}

t_room					*select_short_path(t_room *path, t_room *end)
{
	t_join *room;
	t_room *short_path;

	short_path = NULL;
	room = path->join;
	while (room)
	{
		if (room->room->door == OPEN && short_path == NULL
			&& room->room->step != DEAD_END)
			short_path = room->room;
		else if (short_path)
		{
			if (room->room->door == OPEN &&
				short_path->step > room->room->step
				&& short_path->step != DEAD_END)
				short_path = room->room;
		}
		room = room->next;
	}
	if (short_path == NULL)
		return (NULL);
	end->door = OPEN;
	return (short_path);
}

void					search_short_path(t_lem_in *lem)
{
	t_room		*tmp;
	t_room		*path;
	t_path		*new;

	tmp = lem->start;
	path = select_short_path(tmp, lem->end);
	while (path != NULL)
	{
		CHECK(new = (t_path*)ft_memalloc(sizeof(t_path)));
		new->room = NULL;
		add_short_path(new, path);
		if ((new = start_search(path, new)) && path->step != DEAD_END)
		{
			new->print = NULL;
			lem->path = add_move(lem->path, new);
		}
		path = select_short_path(tmp, lem->end);
	}
}

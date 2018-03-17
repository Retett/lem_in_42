/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:56:44 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/19 14:56:45 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_start_end(t_lem_in *lem, t_room *room)
{
	if (room->pos == START)
	{
		if (lem->start == NULL)
			lem->start = room;
		else
			ft_exit("WHYYY");
	}
	else if (room->pos == END)
	{
		if (lem->end == NULL)
			lem->end = room;
		else
			ft_exit("TO MAN START");
	}
	else
		ft_exit("Something Wrong");
}

void		ft_push_hash(t_lem_in *lem, t_room *room)
{
	add_start_end(lem, room);
	if (room->pos == START)
	{
		room->door = CLOSE;
		ft_push_room(lem, room);
	}
	else
	{
		if (!(lem->room))
		{
			room->next = NULL;
			lem->room = room;
		}
		else
		{
			room->next = lem->room;
			lem->room = room;
		}
	}
}

void		ft_push_room(t_lem_in *lem, t_room *room)
{
	t_room *tmp;

	lem->room_flag = 1;
	if (!(lem->room))
	{
		room->next = NULL;
		lem->room = room;
	}
	else
	{
		tmp = lem->room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = room;
		room->next = NULL;
	}
}

void		ft_push_links(t_room *tmp, t_room *tmp_2)
{
	t_join	*add;
	t_join	*move;

	if ((add = (t_join*)ft_memalloc(sizeof(t_join))) == NULL)
		ft_exit("Error MAlloc");
	add->room = tmp_2;
	if (!(tmp->join))
	{
		tmp->join = add;
		tmp->join->next = NULL;
	}
	else
	{
		move = tmp->join;
		while (move->next)
			move = move->next;
		move->next = add;
		add->next = NULL;
	}
}

t_path		*add_move(t_path *path, t_path *add)
{
	t_path *tmp;
	t_path *move;

	tmp = add;
	tmp->next = NULL;
	if (!(path))
		path = tmp;
	else
	{
		move = path;
		while (move->next)
			move = move->next;
		move->next = tmp;
	}
	return (path);
}

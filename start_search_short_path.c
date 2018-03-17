/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_search_short_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:14:28 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/03/01 17:14:28 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				add_short_path(t_path *path, t_room *room)
{
	t_mark *move;
	t_mark *add;

	add = (t_mark*)ft_memalloc(sizeof(t_mark));
	add->room = room;
	add->next = NULL;
	if (!(path->room))
		path->room = add;
	else
	{
		move = path->room;
		while (move->next)
			move = move->next;
		move->next = add;
	}
}

void				ft_free_all(t_path *path)
{
	t_mark *del;
	t_path *del_2;

	while (path)
	{
		while (path->room)
		{
			del = path->room;
			path->room = path->room->next;
			free(del);
		}
		free(path->room);
		del_2 = path;
		path = path->next;
		free(del_2);
	}
}

t_room				*search_short_neighbor(t_room *pas)
{
	t_room *tmp;
	t_join *sh_pas;

	tmp = NULL;
	sh_pas = pas->join;
	while (sh_pas)
	{
		if (sh_pas->room->door == OPEN && tmp == NULL
			&& sh_pas->room->step != DEAD_END)
			tmp = sh_pas->room;
		else if (tmp)
		{
			if (sh_pas->room->door == OPEN &&
				tmp->step > sh_pas->room->step &&
				sh_pas->room->step != DEAD_END)
				tmp = sh_pas->room;
		}
		sh_pas = sh_pas->next;
	}
	return (tmp);
}

t_path				*start_search(t_room *tmp_2, t_path *path)
{
	t_room *tmp;
	t_room *sh_pas;

	sh_pas = tmp_2;
	sh_pas->door = CLOSE;
	if (sh_pas->pos == END)
		return (path);
	tmp = search_short_neighbor(sh_pas);
	if (tmp == NULL)
	{
		ft_free_all(path);
		return (NULL);
	}
	add_short_path(path, tmp);
	return (start_search(tmp, path));
}

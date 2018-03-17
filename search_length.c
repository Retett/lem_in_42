/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:24:11 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/21 13:24:12 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_mark(t_mark *room, t_room *new)
{
	t_mark	*tmp;
	t_mark	*add;

	if (room->room == NULL)
	{
		room->room = new;
		room->next = NULL;
	}
	else
	{
		tmp = room;
		CHECK(add = (t_mark *)ft_memalloc(sizeof(t_mark) * 1));
		add->room = new;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add;
		add->next = NULL;
	}
}

static void		check_corect_end(t_room *tmp)
{
	t_join	*see;

	see = tmp->join;
	while (see)
	{
		if (see->room->see != BLACK)
			return ;
		see = see->next;
	}
	tmp->step = DEAD_END;
}

static void		add_next_join(t_room *tmp, t_mark *current)
{
	t_join *see;

	see = tmp->join;
	check_corect_end(tmp);
	while (see)
	{
		if (see->room->see != GREY && see->room->see != BLACK)
		{
			add_mark(current, see->room);
			see->room->step = current->room->step + 1;
		}
		see->room->see = GREY;
		see = see->next;
	}
}

void			search_length(t_lem_in *lem)
{
	t_mark	*current;
	t_mark	*tmp;

	CHECK(current = (t_mark *)ft_memalloc(sizeof(t_mark) * 1));
	current->room = NULL;
	add_mark(current, lem->room);
	current->room->step = 0;
	current->room->see = GREY;
	while (current)
	{
		add_next_join(current->room, current);
		current->room->see = BLACK;
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

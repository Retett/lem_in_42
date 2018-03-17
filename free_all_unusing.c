/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_unusing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:22:20 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/03/04 15:22:21 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_all_unusing(t_lem_in *lem)
{
	t_room *room;
	t_join *join;

	room = lem->room;
	while (room)
	{
		while (room->join)
		{
			join = room->join;
			room->join = room->join->next;
			free(join);
		}
		room = room->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:55:21 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/19 15:55:22 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	room_init(t_room **room, int pos, char **line)
{
	(*room)->door = OPEN;
	(*room)->join = NULL;
	(*room)->empty = EMPTY;
	(*room)->pos = pos;
	(*room)->step = 0;
	(*room)->x = ft_atoi(line[2]);
	(*room)->y = ft_atoi(line[1]);
}

static void	same_cord(int x, int y, t_room *lem, char *name)
{
	t_room *tmp;

	tmp = lem;
	while (tmp)
	{
		if (ft_strstr(tmp->name, name) != NULL)
			ft_exit("SAME NAME");
		if (tmp->x == x && tmp->y == y)
			ft_exit("SAME CORD");
		tmp = tmp->next;
	}
}

static int	corect_cord(char *name, char *y, char *x, t_lem_in *lem)
{
	int i;

	i = 0;
	while (x[i] && y[i])
	{
		if (x[i] == '+' || x[i] == '-' || y[i] == '+' || y[i] == '-')
		{
			if (x[i] == '-' || y[i] == '-')
				ft_exit("Error 7");
		}
		else if (ft_isdigit(x[i]) == 0 || ft_isdigit(y[i]) == 0)
			ft_exit("Error 6");
		i++;
	}
	if (i > 11)
		ft_exit("Error 8");
	same_cord(ft_atoi(x), ft_atoi(y), lem->room, name);
	return (1);
}

void		parse_rooms(t_lem_in *lem, char **str)
{
	t_room	*room;
	int		i;

	i = 0;
	if (!(room = (t_room*)ft_memalloc(sizeof(t_room) * 1)))
		ft_exit("Error Malloc");
	if (!(room->name = ft_strdup(str[0])))
		ft_exit("Error Malloc");
	corect_cord(str[0], str[1], str[2], lem);
	room_init(&room, 0, str);
	ft_push_room(lem, room);
	ft_arr_free(str);
}

void		parse_hash(t_lem_in *lem, char **str, int pos)
{
	t_room	*room;
	int		i;

	i = 0;
	if ((room = (t_room*)ft_memalloc(sizeof(t_room) * 1)) == NULL)
		ft_exit("Error Malloc");
	if ((room->name = ft_strdup(str[0])) == NULL)
		ft_exit("Error Malloc");
	if (room->name[0] == 'L')
		ft_exit("wrong name");
	corect_cord(str[0], str[1], str[2], lem);
	room_init(&room, pos, str);
	room->see = 1;
	ft_push_hash(lem, room);
	ft_arr_free(str);
}

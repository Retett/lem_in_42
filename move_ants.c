/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:53:18 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/23 15:53:19 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char			**path_arr(t_path *path)
{
	t_mark	*tmp;
	char	**arr;
	int		i;

	i = 0;
	tmp = path->room;
	CHECK(arr = (char**)ft_memalloc(sizeof(char*) * path->road + 1));
	while (tmp)
	{
		CHECK(arr[i] = ft_strdup(tmp->room->name));
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

static t_path		*chose_pas(t_path *path)
{
	t_path	*tmp;
	t_path	*tmp_2;
	int		check;

	tmp = path;
	tmp_2 = path;
	while (tmp)
	{
		check = tmp->check;
		while (tmp_2)
		{
			if (tmp_2->wait <= check)
			{
				tmp_2->wait++;
				return (tmp_2);
			}
			tmp_2 = tmp_2->next;
		}
		tmp_2 = path;
		tmp = tmp->next;
	}
	return (NULL);
}

static void			run_ants_here_runnn(int *i, int ants, t_path *path)
{
	t_path *add;

	print_add(path, (*i));
	if (path->next && (*i) < ants)
	{
		if ((add = chose_pas(path)) != NULL)
		{
			(*i)++;
			run_ants_here_runnn(i, ants, add);
			return ;
		}
		else
		{
			(*i)++;
			run_ants_here_runnn(i, ants, path->next);
			return ;
		}
	}
	(*i)++;
}

int					move_ants(t_lem_in *lem)
{
	t_path	*tmp;
	int		i;

	if (len_path(lem) == 1)
		return (0);
	i = 1;
	tmp = lem->path;
	init_wait(lem->path);
	lem->path->wait++;
	while (i <= lem->ants)
		run_ants_here_runnn(&i, lem->ants, lem->path);
	while (tmp)
	{
		tmp->name = path_arr(tmp);
		tmp = tmp->next;
	}
	print_move_ants(lem);
	return (0);
}

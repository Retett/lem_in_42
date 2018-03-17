/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:02:48 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/03/01 17:02:49 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		**set_arr(int name, int size)
{
	int		i;
	char	**tab;

	i = 0;
	CHECK(tab = (char**)ft_memalloc(sizeof(char*) * size + 1));
	while (i < size)
		CHECK(tab[i++] = ft_itoa(name));
	tab[i] = NULL;
	return (tab);
}

void			print_add(t_path *path, int name)
{
	t_print_sol		*tmp;
	t_print_sol		*new;

	CHECK(new = (t_print_sol*)ft_memalloc(sizeof(t_print_sol) * 1));
	new->name = set_arr(name, path->road);
	if (!(path->print))
	{
		path->print = new;
		new->next = NULL;
	}
	else
	{
		tmp = path->print;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
}

void			init_wait(t_path *path)
{
	t_path *tmp;

	tmp = path;
	while (tmp)
	{
		tmp->wait = tmp->road;
		tmp->check = tmp->road;
		tmp = tmp->next;
	}
}

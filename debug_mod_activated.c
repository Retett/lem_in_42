/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_mod_activated.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:55:34 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/03/04 16:55:38 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_all_found_path(t_path *path)
{
	int		i;
	t_path	*tmp_2;
	t_mark	*print;

	tmp_2 = path;
	i = 1;
	while (tmp_2)
	{
		print = tmp_2->room;
		printf("path %d : ", i++);
		while (print)
		{
			printf("%s", print->room->name);
			if (print->next)
				printf("-->");
			print = print->next;
		}
		printf("\n");
		tmp_2 = tmp_2->next;
	}
}

void		debug_mod_activated(t_lem_in *lem, int ac, char **av)
{
	if (ac == 1)
		return ;
	if (ft_strequ(av[1], "-p"))
	{
		printf("\n");
		print_all_found_path(lem->path);
	}
	else if (ft_strequ(av[1], "-l"))
	{
		printf("\n");
		system("leaks -quiet lem-in");
	}
}

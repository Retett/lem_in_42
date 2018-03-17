/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:57:19 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/26 14:57:19 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			all_finished(t_path **path)
{
	t_print_sol		*print;
	t_path			*tmp;

	tmp = *path;
	while (tmp)
	{
		print = tmp->print;
		while (print)
		{
			if (print->end != 1)
				return (0);
			print = print->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

static void			print_step_2
	(t_path *path, t_print_sol *tmp, int pos, int *flag)
{
	if (path->name[pos] != NULL)
	{
		if (*flag == 1)
			ft_printf(" ");
		ft_printf("L%s-%s", tmp->name[pos], path->name[pos]);
		if (tmp->name[pos + 1] == NULL)
			tmp->end = 1;
		*flag = 1;
		tmp->name[pos][0] = '-';
	}
}

static int			print_step_1(t_path *path, int *flag)
{
	t_print_sol			*tmp;
	int					i;

	tmp = path->print;
	while (tmp)
	{
		i = 0;
		while (tmp->name[i] != 0)
		{
			if (tmp->name[i][0] != '-')
			{
				print_step_2(path, tmp, i, flag);
				if ((i - 1) < 0)
					return (0);
				i -= 2;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (1);
}

void				print_move_ants(t_lem_in *lem)
{
	t_path		*tmp;
	int			finished;
	int			flag;

	tmp = NULL;
	finished = 0;
	while (1)
	{
		flag = 0;
		tmp = lem->path;
		while (tmp)
		{
			print_step_1(tmp, &flag);
			tmp = tmp->next;
		}
		finished = all_finished(&lem->path);
		if (finished == 0)
			ft_printf("\n");
		else if (finished == 1)
			break ;
	}
	ft_printf("\n");
}

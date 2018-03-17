/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:07:11 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/19 16:07:12 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_arr_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void			ft_exit(char *error)
{
	ft_dprintf(1, "ERROR\n");
	(void)error;
	exit(1);
}

char			*ft_next(char *s1, char *s2)
{
	char	*str;
	char	*tmp;
	size_t	len;

	tmp = s1;
	if ((char*)s1 == NULL || (char*)s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strcat(ft_strcpy(str, s1), s2);
	str[len] = '\0';
	free(tmp);
	return (str);
}

int				ft_check(t_room *lem, char *str)
{
	t_join *tmp;

	tmp = lem->join;
	while (tmp)
	{
		if (ft_strequ(tmp->room->name, str) == 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

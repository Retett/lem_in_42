/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:13:38 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/04 14:13:40 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_swap_int(int *a, int *b)
{
	int temp;

	if (a != NULL && b != NULL)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
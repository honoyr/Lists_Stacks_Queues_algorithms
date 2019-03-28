/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:34:49 by dgonor            #+#    #+#             */
/*   Updated: 2019/03/27 23:34:53 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*NthLastCity(struct s_city *city, int n)
{
	struct s_city	*curr;
	int				offset;

	curr = city;
	offset = -n;
	while (city)
	{
		if (offset > 0)
			curr = curr->next;
		offset++;
		city = city->next;
	}
	if (curr && offset)
		return (curr->name);
	return (0);
}

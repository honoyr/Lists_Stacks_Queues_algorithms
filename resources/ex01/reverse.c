/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:06:23 by dgonor            #+#    #+#             */
/*   Updated: 2019/03/27 17:06:25 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void printReverse(struct s_node *lst)
{
	static int i = 0;

	if (!lst)
		return ;
	i++;
	printReverse(lst->next);
	printf("%s", lst->word);
	i--;
	i ? printf(" ") : printf("\n");
}
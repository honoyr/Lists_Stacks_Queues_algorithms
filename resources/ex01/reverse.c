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
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

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
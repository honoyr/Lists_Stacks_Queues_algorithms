/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:16:35 by dgonor            #+#    #+#             */
/*   Updated: 2019/03/27 12:16:41 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

char *precious(int *text, int size)
{
	struct s_node	*cs = NULL;
	struct s_node	*tmp = NULL;
	char			*str = NULL;

	
	if (!(cs = (struct s_node*)malloc(sizeof(struct s_node))))
		return NULL;
	if(!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return NULL;
	tmp  = cs;
	for(int i = 0; i < 80; i++)
	{
		tmp->c = CS[i];
		tmp->next = (struct s_node*)malloc(sizeof(struct s_node));
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
		tmp = tmp->next;

	}
	cs->prev = tmp->prev;
	tmp = tmp->prev;
	tmp->next = cs;
	tmp = cs;
	printf("here\n");
	for(int i = 0; i < size; i++)
	{
		if (text[i] < 0)
		{
			for (int j = text[i]; j < 0; j++)
				tmp = tmp->prev;
			str[i] = tmp->c;
			printf("%c", tmp->c);
		}
		else
		{
			for(int k = 0; k < text[i]; k++)
				tmp = tmp->next;
			str[i] = tmp->c;
			printf("%c", tmp->c);
		}
	}
	return str;
}
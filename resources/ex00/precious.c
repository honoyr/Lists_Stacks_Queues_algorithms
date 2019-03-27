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
	struct s_node *cs = NULL;
	struct s_node *tmp = NULL;

	if (!(cs = (struct s_node*)malloc(sizeof(struct s_node))))
		return NULL;
	tmp  = cs;
	for(int i = 0; i < 80; i++)
	{
		tmp->c = CS[i];
		// printf("CHAR = %c\n", tmp->c);
		tmp->next = (struct s_node*)malloc(sizeof(struct s_node));
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
		// printf("CHAR = %c\n", tmp->prev->c);
		tmp = tmp->next;

	}
	// printf("CHAR = %c\n", tmp->c);
	cs->prev = tmp->prev;
	tmp = tmp->prev;
	tmp->next = cs;
	tmp = cs;
	// for(int i = 0; i < 80; i++)
	// {
		
	// 	tmp = tmp->next;
	// 	printf("CHAR = %c\n", tmp->c);
	// }
	// printf("\n");
	// tmp = cs;
	// printf("SIZE = %i\n", size);
	// for(int i = 0; i < (size); i++)
	// {
	// 	printf("%i\n", text[i]);
	// }
	tmp = cs;
	// printf("\nCHAR =%c\n", tmp->c);
	for(int i = 0; i < size; i++)
	{
		// printf("%i\n\n", text[i]);
		if (text[i] < 0)
		{
			// printf("\nCHAR1 =%c\n", tmp->c);
			// printf("\nNUM = %i\n", text[i]);
			for (int j = text[i]; j < 0; j++)
			{
				printf("\nNUM1 =%i\n", j);
				tmp = tmp->prev;
			}
			printf("%c", tmp->c);
		}
		else
		{
			for(int k = 0; k < text[i]; k++)
			{
				// printf("\nCHAR2 =%c\n", tmp->c);
				tmp = tmp->next;
			}
			printf("%c", tmp->c);
		}
	}
	printf("\n");
	return "OK";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:46:02 by dgonor            #+#    #+#             */
/*   Updated: 2019/03/27 21:46:04 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

struct s_stack *initStack(void)
{
	struct s_stack *stack = NULL;

	if (!(stack = (struct s_stack*)malloc(sizeof(struct s_stack))))
		return NULL;
	stack->item = NULL;
	return stack;

}

int pop(struct s_stack *stack)
{
	struct s_item *del = NULL;
	int			id;

	del = stack->item;
	id = del->idx;
	stack->item = stack->item->next;
	free(del);
	return id;
}

void push(struct s_stack *stack, int idx)
{
	if (stack)
	{
		struct s_item	*tmp = NULL;
		if (!(tmp = (struct s_item*)malloc(sizeof(struct s_item))))
		{
			printf("%s\n", "Memory wasn't allocated");
			return ;
		}
		if (!(stack->item))
		{
			tmp->next = NULL;
			stack->item = tmp;
		}
		else
		{
			tmp->idx = idx;
			tmp->next = stack->item;
			stack->item = tmp;
		}
	}
}

char			*console(void)
{
	struct s_stack	*stack = initStack();
	char			*msg = calloc(1, 256);
	char			*line = NULL;
	size_t			len = 255;
	ssize_t			word;
	int				i = 0;
	int				idx;

	while (1)
	{
		printf("?: ");
		word = getline(&line, &len, stdin);
		if (!strncmp(line, "UNDO", 4))
		{
			if (!stack->item)
				continue ;
			idx = pop(stack);
			memset(&msg[idx], '\0', 255 - idx);
			i = idx;
		}
		else if (!strncmp(line, "SEND", 4))
		{
			while (stack->item)
				pop(stack);
			free(stack);
			return (msg);
		}
		else
		{
			push(stack, i);
			strncat(msg, line, word - 1);
			strncat(msg, " ", 1);
			i += word;
		}
		printf("%s\n", msg);
	}
	return (NULL);
}
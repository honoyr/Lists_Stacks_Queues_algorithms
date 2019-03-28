/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:48:35 by dgonor            #+#    #+#             */
/*   Updated: 2019/03/27 17:48:36 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack *stackInit(void)
{
	struct s_stack *stack = NULL;

	if (!(stack = (struct s_stack*)malloc(sizeof(struct s_stack))))
		return NULL;
	if (!(stack->item = (struct s_item*)malloc(sizeof(struct s_item))))
		return NULL;
	stack->item->word = NULL;
	stack->item->next = NULL;
	return stack;

}

void pop(struct s_stack *stack)
{
	struct s_item *del = NULL;

	del = stack->item;
	stack->item = stack->item->next;
	free(del);
}

void push(struct s_stack *stack, char *word)
{
	if (stack && word)
	{
		if (!stack->item->word)
			stack->item->word = word;
		else
		{
			struct s_item *tmp = NULL;
			if (!(tmp = (struct s_item*)malloc(sizeof(struct s_item))))
			{
				printf("%s\n", "Doesn't allocated memory");
				// return ;
			}
			tmp->word = word;
			tmp->next = stack->item;
			stack->item = tmp;
		}
	}
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack	*stack = stackInit();
	struct s_item	*tmp_item = NULL;
	struct s_node	*tmp_lst = lst;

	while (tmp_lst)
	{
		push(stack, tmp_lst->word);
		tmp_lst = tmp_lst->next;
	}
	tmp_item = stack->item;
	while(tmp_item)
	{
		printf("%s\n", tmp_item->word);
		tmp_item = tmp_item->next;
	}
}

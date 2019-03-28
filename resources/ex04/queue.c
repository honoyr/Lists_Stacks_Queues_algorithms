/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:23:55 by dgonor            #+#    #+#             */
/*   Updated: 2019/03/27 23:23:57 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"
#include <stdlib.h>

struct s_queue *queueInit(void)
{
	struct s_queue *queue;

	if (!(queue = malloc(sizeof(struct s_queue))))
		return NULL;
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

char *dequeue(struct s_queue *queue)
{
	struct s_node	*node;
	char			*message;
	if (!queue->first)
		return (NULL);
	node = queue->first;
	message = node->message;
	queue->first = node->next;
	if (!queue->first)
		queue->last = NULL;
	free(node);
	return (message);

}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *node;

	node = malloc(sizeof(struct s_node));
	node->message = message;
	node->next = NULL;
	if (!queue->first)
		queue->first = node;
	if (queue->last)
		queue->last->next = node;
	queue->last = node;
}

char *peek(struct s_queue *queue)
{
	return ((queue && queue->first) ? queue->first->message : NULL);
}

int isEmpty(struct s_queue *queue)
{
	return ((!queue || !queue->first));
}
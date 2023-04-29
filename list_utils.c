/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:49:27 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 15:21:38 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int nbr)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}

int	ft_lstsize(t_node *a_head)
{
	int		size;
	t_node	*temp;

	if (!a_head)
		return (0);
	size = 0;
	temp = a_head;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	ft_new_head(t_node *a_head, int new)
{
	t_node	*new_node;

	new_node = ft_lstnew(new);
	new_node->nbr = new;
	new_node->next = a_head;
	a_head = new_node;
}

t_node	*ft_lstlast(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstaddback(t_node *node, t_node *new)
{
	if (!node || !new)
		return ;
	while (node->next != NULL)
		node = node->next;
	node->next = new;
}

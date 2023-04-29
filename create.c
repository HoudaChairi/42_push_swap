/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:47:37 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 15:23:52 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_nbr(t_node *head, int size)
{
	t_node	*curr;
	t_node	*t_head;

	t_head = head;
	while (t_head != NULL)
	{
		t_head->rank = size;
		t_head = t_head->next;
	}
	curr = head;
	t_head = head;
	while (curr != NULL)
	{
		while (t_head != NULL)
		{
			if (curr->nbr < t_head->nbr)
				curr->rank--;
			t_head = t_head->next;
		}
		t_head = head;
		curr = curr->next;
	}
}

t_node	*create_stack(t_node *a_head, t_data *ps)
{
	t_node	*node;
	int		i;

	i = 0;
	a_head = ft_lstnew(ps->array[i++]);
	node = a_head;
	while (i < ps->ct_nbr)
	{
		ft_lstaddback(node, ft_lstnew(ps->array[i]));
		i++;
	}
	return (node);
}

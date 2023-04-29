/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:11:10 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 11:07:34 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(t_node *node)
{
	int		val;

	val = node->nbr;
	while (node->next != NULL)
	{
		if (val < node->next->nbr)
			val = node->next->nbr;
		node = node->next;
	}
	return (val);
}

int	node_pos(t_node *node)
{
	int	pos;
	int	max;

	pos = 1;
	max = max_value(node);
	while (node->next != NULL)
	{
		if (max == node->nbr)
			return (pos);
		node = node->next;
		pos++;
	}
	return (pos);
}

void	back_to_a(t_node **a_head, t_node **b_head)
{
	rank_nbr(*b_head, ft_lstsize(*b_head));
	while (*b_head)
	{
		rank_nbr(*b_head, ft_lstsize(*b_head));
		if (ft_lstsize(*b_head) == 1)
			pa(a_head, b_head, 1);
		else if (node_pos(*b_head) <= ft_lstsize(*b_head) / 2)
		{
			while ((*b_head)->nbr != max_value(*b_head))
				rb(b_head, 1);
			pa(a_head, b_head, 1);
		}
		else
		{
			while (ft_lstlast(*b_head)->nbr != max_value(*b_head))
				rrb(b_head, 1);
			rrb(b_head, 1);
			pa(a_head, b_head, 1);
		}
	}
}

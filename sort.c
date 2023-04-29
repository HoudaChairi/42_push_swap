/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:47:33 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 12:36:30 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a_head)
{
	t_node	*t_head;

	if (!(*a_head))
		return ;
	t_head = *a_head;
	if (t_head->nbr > t_head->next->nbr)
		sa(*a_head, 1);
}

void	sort_three(t_node **a_head)
{
	rank_nbr(*a_head, ft_lstsize(*a_head));
	if (!(*a_head))
		return ;
	if ((*a_head)->rank == 3)
		ra(a_head, 1);
	else if ((*a_head)->next->rank == 3)
		rra(a_head, 1);
	if ((*a_head)->nbr > (*a_head)->next->nbr)
		sa(*a_head, 1);
}

void	sort_foor(t_node **a_head, t_node **b_head)
{
	t_node	*tmp;

	tmp = *a_head;
	rank_nbr(*a_head, ft_lstsize(*a_head));
	if (!(*a_head))
		return ;
	if (tmp->next->rank == 1)
		ra(a_head, 1);
	else if (tmp->next->next->rank == 1)
	{
		ra(a_head, 1);
		ra(a_head, 1);
	}
	else if (tmp->next->next->next->rank == 1)
		rra(a_head, 1);
	pb(b_head, a_head, 1);
	sort_three(a_head);
	pa(a_head, b_head, 1);
}

void	sort_five(t_node **a_head, t_node **b_head)
{
	t_node	*tmp;

	tmp = *a_head;
	rank_nbr(*a_head, ft_lstsize(*a_head));
	if (!(*a_head))
		return ;
	if (tmp->next->rank == 1)
		ra(a_head, 1);
	else if (tmp->next->next->rank == 1)
	{
		ra(a_head, 1);
		ra(a_head, 1);
	}
	else if (tmp->next->next->next->rank == 1)
	{
		rra(a_head, 1);
		rra(a_head, 1);
	}
	else if (tmp->next->next->next->next->rank == 1)
		rra(a_head, 1);
	pb(b_head, a_head, 1);
	sort_foor(a_head, b_head);
	pa(a_head, b_head, 1);
}

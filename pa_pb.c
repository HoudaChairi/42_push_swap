/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:36:39 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 15:25:50 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a_head, t_node **b_head, int i)
{
	t_node	*save_a;
	t_node	*save_b;

	if (!*b_head)
		return ;
	save_a = *a_head;
	save_b = *b_head;
	*b_head = (*b_head)->next;
	*a_head = save_b;
	(*a_head)->next = save_a;
	if (ft_lstsize(*b_head) == 0)
		b_head = NULL;
	if (i == 1)
		ft_printf("pa\n");
}

void	pb(t_node **b_head, t_node **a_head, int i)
{
	t_node	*save_b;
	t_node	*save_a;

	if (!*a_head)
		return ;
	save_b = *b_head;
	save_a = *a_head;
	*a_head = (*a_head)->next;
	*b_head = save_a;
	(*b_head)->next = save_b;
	if (ft_lstsize(*a_head) == 0)
		a_head = NULL;
	if (i == 1)
		ft_printf("pb\n");
}

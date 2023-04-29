/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ra_rb_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:06:08 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/26 18:35:30 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a_head, int x)
{
	int		i;
	int		size;
	t_node	*t_head;
	t_node	*n1;
	t_node	*last;

	i = 1;
	size = ft_lstsize(*a_head);
	if (size <= 1)
		return ;
	t_head = (*a_head);
	n1 = (*a_head);
	last = ft_lstlast(*a_head);
	while (i < size - 1)
	{
		t_head = t_head->next;
		i++;
	}
	t_head->next = NULL;	
	last->next = n1;
	(*a_head) = last;
	if (x == 1)
		ft_printf("rra\n");
}

void	rrb(t_node **b_head, int x)
{
	int		i;
	int		size;
	t_node	*t_head;
	t_node	*last;
	t_node	*n1;

	i = 1;
	size = ft_lstsize(*b_head);
	if (size <= 1)
		return ;
	t_head = (*b_head);
	n1 = (*b_head);
	last = ft_lstlast(*b_head);
	while (i < size - 1)
	{
		t_head = t_head->next;
		i++;
	}
	t_head->next = NULL;
	last->next = n1;
	(*b_head) = last;
	if (x == 1)
		ft_printf("rrb\n");
}

void	rrr(t_node **a_head, t_node **b_head, int i)
{
	rra(a_head, i);
	rrb(b_head, i);
	if (i == 1)
		ft_printf("rrr\n");
}
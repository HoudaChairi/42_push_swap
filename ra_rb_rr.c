/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:48:37 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 15:22:28 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a_head, int i)
{
	t_node	*t_head;
	t_node	*last;

	if (!*a_head)
		return ;
	t_head = *a_head;
	last = ft_lstlast(*a_head);
	*a_head = t_head->next;
	t_head->next = NULL;
	last->next = t_head;
	last = t_head;
	if (i == 1)
		ft_printf("ra\n");
}

void	rb(t_node **b_head, int i)
{
	t_node	*t_head;
	t_node	*last;

	if (!*b_head)
		return ;
	t_head = *b_head;
	last = ft_lstlast(*b_head);
	*b_head = t_head->next;
	t_head->next = NULL;
	last->next = t_head;
	last = t_head;
	if (i == 1)
		ft_printf("rb\n");
}

void	rr(t_node **a_head, t_node **b_head, int i)
{
	ra(a_head, i);
	rb(b_head, i);
	if (i == 1)
		ft_printf("rr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:27:01 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 15:24:11 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *head, t_node *next)
{
	int	tmp;

	if (!head || !next)
		return ;
	tmp = head->nbr;
	head->nbr = next->nbr;
	next->nbr = tmp;
}

void	sa(t_node *a_head, int i)
{
	if (ft_lstsize(a_head) <= 1)
		return ;
	ft_swap(a_head, a_head->next);
	if (i == 1)
		ft_printf("sa\n");
}

void	sb(t_node *b_head, int i)
{
	if (ft_lstsize(b_head) <= 1)
		return ;
	ft_swap(b_head, b_head->next);
	if (i == 1)
		ft_printf("sb\n");
}

void	ss(t_node *a_head, t_node *b_head, int i)
{
	sa(a_head, i);
	sb(b_head, i);
	if (i == 1)
		ft_printf("ss\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:10:08 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 11:14:36 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	range(int min, int rmax, int rank)
{
	int	max;

	max = min + rmax;
	if (rank >= min && rank < max)
		return (0);
	else if (rank < min)
		return (-1);
	else if (rank >= max)
		return (5);
	return (3);
}

void	sort_hundred(t_node **a_head, t_node **b_head)
{
	int	r;

	r = 1;
	rank_nbr(*a_head, ft_lstsize(*a_head));
	while (*a_head)
	{
		if (range(r, 15, ((*a_head)->rank)) == 0)
		{
			pb(b_head, a_head, 1);
			r++;
		}
		else if (range(r, 15, ((*a_head)->rank)) == -1)
		{
			pb(b_head, a_head, 1);
			rb(b_head, 1);
			r++;
		}
		else if (range(r, 15, ((*a_head)->rank)) == 5)
			ra(a_head, 1);
	}
	back_to_a(a_head, b_head);
}

void	sort_five_hundred(t_node **a_head, t_node **b_head)
{
	int	r;

	r = 1;
	rank_nbr(*a_head, ft_lstsize(*a_head));
	while (*a_head)
	{
		if (range(r, 35, ((*a_head)->rank)) == 0)
		{
			pb(b_head, a_head, 1);
			r++;
		}
		else if (range(r, 35, ((*a_head)->rank)) == -1)
		{
			pb(b_head, a_head, 1);
			rb(b_head, 1);
			r++;
		}		
		else if (range(r, 35, ((*a_head)->rank)) == 5)
			ra(a_head, 1);
	}
	back_to_a(a_head, b_head);
}

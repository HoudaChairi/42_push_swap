/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depart.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:31:36 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 14:32:41 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_data *ps)
{
	ps->s = NULL;
	ps->array = NULL;
}

int	check_sort(t_node *a_head)
{
	t_node	*t_head;

	t_head = a_head;
	while (t_head->next)
	{
		if (t_head->nbr > t_head->next->nbr)
			return (1);
		t_head = t_head->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:32:54 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 17:45:54 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstclear(t_node	*node)
{
	t_node	*tmp;
	t_node	*tmp_next;

	if (!node)
		return ;
	tmp = node;
	while (tmp)
	{
		tmp_next = tmp->next;
		free (tmp);
		tmp = tmp_next;
	}
	node = NULL;
}

void	ft_free_tab(t_data *ps)
{
	int	i;

	i = 0;
	if (ps->tab)
	{
		while (ps->tab[i])
			free(ps->tab[i++]);
		free(ps->tab);
	}
}

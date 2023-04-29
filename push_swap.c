/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:49:29 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 17:51:40 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting(int argc, t_node *a_head, t_node *b_head)
{
	if (check_sort(a_head))
	{
		if (argc == 3)
			sort_two(&a_head);
		else if (argc == 4)
			sort_three(&a_head);
		else if (argc == 5)
			sort_foor(&a_head, &b_head);
		else if (argc == 6)
			sort_five(&a_head, &b_head);
		else if (argc > 6 && argc <= 101)
			sort_hundred(&a_head, &b_head);
		else if (argc > 101)
			sort_five_hundred(&a_head, &b_head);
	}
}

int	main(int argc, char **argv)
{
	t_data		ps;
	t_stacks	st;

	if (argc < 2)
		exit(1);
	init(&ps);
	check_andtab(&ps, argv);
	st.a_head = NULL;
	st.b_head = NULL;
	st.a_head = create_stack(st.a_head, &ps);
	ft_sorting(argc, st.a_head, st.b_head);
	free(ps.array);
	lstclear(st.a_head);
	return (0);
}

	// ft_printf("stack [A]\n");
	// while (st.a_head != NULL)
	// {
	// 	ft_printf("%d\n", st.a_head->nbr);
	// 	st.a_head = st.a_head->next;
	// }
	// ft_printf("stack [B]\n");
	// while (st.b_head != NULL)
	// {
	// 	ft_printf("%d\n", st.b_head->nbr);
	// 	st.b_head = st.b_head->next;
	// }
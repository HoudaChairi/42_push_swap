/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:32:04 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 17:49:32 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(t_node *a_head, t_node *b_head, t_data *ps)
{
	write(2, "Error\n", 6);
	free(ps->array);
	lstclear(a_head);
	lstclear(b_head);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;	

	i = 0;
	while (1)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			if (s1[i] == '\0' && s2[i] == '\0')
				return (0);
			else
				return (1);
		}
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	instructions(char *line, t_node **a_head, t_node **b_head, t_data *ps)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(*a_head, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(*b_head, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(*a_head, *b_head, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a_head, b_head, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b_head, a_head, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a_head, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b_head, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a_head, b_head, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a_head, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b_head, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a_head, b_head, 0);
	else
		err(*a_head, *b_head, ps);
}

void	read_line(t_node *a_head, t_node *b_head, t_data *ps)
{	
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		instructions(line, &a_head, &b_head, ps);
		free (line);
		line = get_next_line(0);
	}
	if (!check_sort(a_head) && !b_head)
		ft_printf("OK");
	else
		ft_printf("KO");
}

int	main(int argc, char **argv)
{
	t_data		ps;
	t_stacks	st;

	if (argc < 2)
		exit(1);
	init(&ps);
	check_andtab(&ps, argv);
	st.a_head = create_stack(st.a_head, &ps);
	st.b_head = NULL;
	read_line(st.a_head, st.b_head, &ps);
	free(ps.array);
	lstclear(st.a_head);
	lstclear(st.b_head);
}

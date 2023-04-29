/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:49:39 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 15:16:02 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "stdlib.h"
# include <limits.h>
# include <unistd.h>

typedef struct s_data
{
	char	**tab;
	int		*array;
	char	*s;
	int		ct_nbr;
}	t_data;

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
	int				rank;
}	t_node;

typedef struct s_stacks
{
	struct s_node	*a_head;
	struct s_node	*b_head;	
}	t_stacks;

char	**ft_split(char const *s, char c);

long	ft_atoi(char *str);
int		checkerr(char *s);
char	**splt(t_data *ps);
int		check_duplicate(t_data *ps);
int		*to_nbr(t_data *ps);
void	check_andtab(t_data *ps, char **argv);

t_node	*ft_lstnew(int nbr);
t_node	*ft_lstlast(t_node *node);
int		ft_lstsize(t_node *head);
void	ft_lstaddback(t_node *node, t_node *new);

void	sa(t_node *a_head, int i);
void	sb(t_node *b_head, int i);
void	ss(t_node *a_head, t_node *b_head, int i);
void	ra(t_node **a_head, int i);
void	rb(t_node **b_head, int i);
void	rr(t_node **a_head, t_node **b_head, int i);
void	rra(t_node **a_head, int i);
void	rrb(t_node **b_head, int i);
void	rrr(t_node **a_head, t_node **b_head, int i);
void	pb(t_node **b_head, t_node **a_head, int i);
void	pa(t_node **a_head, t_node **b_head, int i);
void	ft_swap(t_node *head, t_node *next);
void	sort_two(t_node **a_head);
void	sort_three(t_node **a_head);
void	sort_five(t_node **a_head, t_node **b_head);
void	sort_foor(t_node **a_head, t_node **b_head);
void	rank_nbr(t_node *head, int size);
void	sort_hundred(t_node **a_head, t_node **b_head);
void	sort_five_hundred(t_node **a_head, t_node **b_head);
void	back_to_a(t_node **a_head, t_node **b_head);

t_node	*create_stack(t_node *a_head, t_data *ps);
//bonus 
// void	read_line(t_node *a_head, t_node *b_head);

void	ft_free_tab(t_data *ps);
void	lstclear(t_node	*a_head);
void	init(t_data *ps);
int		check_sort(t_node *a_head);

#endif
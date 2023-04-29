/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_and_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:40:32 by hchairi           #+#    #+#             */
/*   Updated: 2023/04/29 15:21:02 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkerr(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

int	check_duplicate(t_data *ps)
{
	int		i;
	int		j;

	i = 0;
	while (ps->tab[i])
	{
		j = i + 1;
		while (ps->tab[j])
		{
			if (ft_atoi(ps->tab[i]) == ft_atoi(ps->tab[j]))
			{
				write(1, "Error\n", 6);
				ft_free_tab(ps);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**splt(t_data *ps)
{
	int		i;

	i = 0;
	ps->tab = NULL;
	ps->tab = ft_split(ps->s, ' ');
	ps->ct_nbr = 0;
	while (ps->tab[i])
	{
		if (ft_atoi(ps->tab[i]) == 2147483648
			|| (ft_atoi(ps->tab[i]) < INT_MIN || ft_atoi(ps->tab[i]) > INT_MAX))
		{
			write(1, "Error\n", 6);
			free(ps->s);
			ft_free_tab(ps);
			exit (1);
		}
		ps->ct_nbr++;
		i++;
	}
	free(ps->s);
	return (ps->tab);
}

int	*to_nbr(t_data *ps)
{
	int	i;

	i = 0;
	ps->array = malloc(ps->ct_nbr * sizeof(int));
	while (i < ps->ct_nbr)
	{
		ps->array[i] = ft_atoi(ps->tab[i]);
		i++;
	}
	return (ps->array);
}

void	check_andtab(t_data *ps, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		ps->s = ft_strjoin(ps->s, argv[i]);
		ps->s = ft_strjoin(ps->s, " ");
		if (checkerr(argv[i]))
		{
			write(2, "Error\n", 6);
			free(ps->s);
			exit (1);
		}
		i++;
	}
	ps->tab = splt(ps);
	if (!ps->tab)
	{
		write(2, "Error\n", 6);
		free(ps->s);
		exit (1);
	}
	check_duplicate(ps);
	to_nbr(ps);
	ft_free_tab(ps);
}

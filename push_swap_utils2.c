/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:56:59 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/19 10:26:58 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	while (!check_index(*stack_a))
	{
		tmp = *stack_a;
		while (tmp->index == -1)
			tmp = tmp->next;
		flag_stack(*stack_a);
		while ((*stack_a)->index == -1)
		{
			if (tmp->flag > 0)
			{
				ra(stack_a);
				write(1, "ra\n", 3);
			}
			else if (tmp->flag < 0)
			{
				rra(stack_a);
				write(1, "rra\n", 4);
			}
		}
		pb(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
}

void	tri_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*tab[4];
	int		i;
	int		size_b;
	int		temp;

	i = 0;
	size_b = size_stack(*stack_b);
	while (i < size_b)
	{
		tab[0] = find_min(*stack_a);
		tab[1] = find_max(*stack_a);
		tab[2] = *stack_a;
		tab[3] = *stack_b;
		flag_stack(*stack_a);
		if (tab[3]->content > tab[1]->content)
			temp = tab[0]->flag;
		else if (tab[3]->content < tab[1]->content)
		{
			tab[0] = tab[1];
			tab[2] = put_flags_to_stack(&tab[2], &tab[0], stack_a, stack_b);
			temp = tab[0]->flag;
		}
		ft_temp(temp, stack_a, stack_b);
		i++;
	}
}

void	ft_temp(int temp, t_list **stack_a, t_list **stack_b)
{
	if (temp > 0)
	{
		while (temp > 1)
		{
			ra(stack_a);
			write(1, "ra\n", 3);
			temp--;
		}
		pa(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	if (temp < 0)
	{
		temp = temp * -1;
		while (temp >= 1)
		{
			rra(stack_a);
			write(1, "rra\n", 4);
			temp--;
		}
		pa(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
}

t_list	*put_flags_to_stack(t_list **x, t_list **y, t_list **a, t_list **b)
{
	while (*x)
	{
		flag_stack(*a);
		if ((*x)->content > (*b)->content
			&& (*x)->content < (*y)->content)
			*y = *x;
		*x = (*x)->next;
	}
	return (*a);
}

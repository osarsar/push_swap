/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:58:45 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/19 12:11:18 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_stack(char **av)
{
	int		i;
	char	*string;
	char	**split;

	string = ft_strdup("");
	i = 1;
	while (av[i])
	{
		string = ft_strjoin(string, av[i]);
		string = ft_strjoin(string, " ");
		i++;
	}
	i = 0;
	split = ft_split(string, ' ');
	check_valid_stack(string);
	return (split);
}

int	creat_stack(t_list	*stack_a, char **split)
{
	t_list	*tab;
	int		i;

	i = 0;
	while (split[i])
	{
		tab = ft_lstnew(ft_atoi(split[i]));
		ft_lstadd_back(&stack_a, tab);
		i++;
	}
	free(stack_a);
	return (i);
}

int	check_index(t_list *stack_a)
{
	int		i;
	t_list	*head;

	i = 0;
	head = stack_a;
	while (head)
	{
		if (head->index != -1)
			return (0);
		head = head->next;
	}
	return (1);
}

void	affiche_stack(t_list *stack_a, t_list *stack_b)
{
	t_list	*head;

	while (stack_b)
	{
		printf("stack_b = %d\n", stack_b->content);
		stack_b = stack_b->next;
	}
	head = stack_a;
	while (head)
	{
		printf("stack_a = %d -> %d\n", head->content, head->flag);
		head = head->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_b;
	t_list	*stack_a;
	t_list	*head;
	char	**split;
	int		len;

	if (ac > 2)
	{
		stack_a = ft_lstnew(42);
		stack_b = ft_lstnew(1337);
		split = split_stack(av);
		creat_stack(stack_a, split);
		check_same_number(stack_a);
		stack_a = stack_a->next;
		check_sort(stack_a);
		longest_increasing_subsequence(stack_a);
		len = max_subsequence(stack_a);
		head = stack_a;
		add_minus_one(head, len);
		push_b(&stack_a, &stack_b);
		head = stack_b;
		while (head->next->next)
			head = head->next;
		head->next = NULL;
		tri_stack(&stack_a, &stack_b);
		final_tri_stack(&stack_a);
		affiche_stack(stack_a, stack_b);
	}
	else if (ac == 2)
	{
		ft_putstr_fd("Error", 2);
		exit(1);
	}
}

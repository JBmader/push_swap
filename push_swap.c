/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:53:49 by jmader            #+#    #+#             */
/*   Updated: 2024/12/17 15:22:01 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

/*
void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	if (a->top > b->top)
		i = a->top;
	else
		i = b->top;
	printf("Top de a : %d - ", a->top);
	printf("Top de b : %d\n", b->top);
	while (i >= 0)
	{
		printf("a[%d] : %d - ", i, a->data[i]);
		printf("b[%d] : %d\n", i, b->data[i]);
		i--;
	}
}*/

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i > 0)
	{
		if (stack->data[i] > stack->data[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	sort_three(t_stack *a)
{
	if (is_sorted(a))
		return ;
	if (a->data[a->top] > a->data[a->top - 1])
		sa(a);
	if (a->data[a->top - 1] > a->data[a->top - 2])
	{
		rra(a);
		if (a->data[a->top] > a->data[a->top - 1])
			sa(a);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->top > 2)
	{
		while (a->data[a->top] < 2)
			pb(a, b);
		if (a->top == 2)
			break ;
		if (a->data[0] < 2)
			rra(a);
		else
			ra(a);
	}
	sort_three(a);
	while (b->top > -1)
	{
		pa(b, a);
		if (a->data[a->top] > a->data[a->top - 1])
			sa(a);
	}
}

void	push_swap(int *data_a, int size)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.data = data_a;
	stack_a.top = size - 1;
	stack_b.data = ft_calloc(size + 1, sizeof(int));
	stack_b.top = -1;
	if (!stack_b.data || is_sorted(&stack_a))
	{
		free(stack_b.data);
		return ;
	}
	if (size <= 5)
		sort_five(&stack_a, &stack_b);
	else
		sort_large_stack(&stack_a, &stack_b, size);
	free(stack_b.data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbmader <jbmader@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:32:55 by jmader            #+#    #+#             */
/*   Updated: 2024/12/10 19:48:54 by jbmader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top > 0)
	{
		tmp = stack->data[stack->top];
		stack->data[stack->top] = stack->data[stack->top - 1];
		stack->data[stack->top - 1] = tmp;
	}
}

void	push(t_stack *stacksrc, t_stack *stackdst)
{
	int	topsrc;

	if (stacksrc->top > -1)
	{
		topsrc = stacksrc->data[stacksrc->top];
		stacksrc->data[stacksrc->top] = 0;
		stacksrc->top--;
		stackdst->top++;
		stackdst->data[stackdst->top] = topsrc;
	}
}

void	rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->top;
	tmp = stack->data[stack->top];
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->data[0];
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->top] = tmp;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

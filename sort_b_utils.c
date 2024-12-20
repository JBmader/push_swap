/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:12:17 by jmader            #+#    #+#             */
/*   Updated: 2024/12/17 15:18:01 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_top(t_stack *b)
{
	int	i;
	int	max;
	int	max_pos;

	i = 0;
	max = b->data[0];
	max_pos = 0;
	while (i <= b->top)
	{
		if (b->data[i] > max)
		{
			max = b->data[i];
			max_pos = i;
		}
		i++;
	}
	if (max_pos < b->top / 2)
		return (-(max_pos + 1));
	else
		return (b->top - max_pos);
}

int	shift_top(t_stack *b, int value)
{
	int	i;

	i = b->top;
	while (i > 0)
	{
		if ((b->data[i] > value) && (b->data[i -1] < value))
			break ;
		i--;
	}
	if (i - 1 < b->top / 2)
		return (-i);
	else
		return (b->top - i + 1);
}

int	is_mini(t_stack *b, int value)
{
	int	i;

	i = 0;
	while (i <= b->top)
	{
		if (b->data[i] < value)
			return (0);
		i++;
	}
	return (1);
}

int	is_maxi(t_stack *b, int value)
{
	int	i;

	i = 0;
	while (i <= b->top)
	{
		if (b->data[i] > value)
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:22:38 by jbmader           #+#    #+#             */
/*   Updated: 2024/12/17 18:14:29 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_top(t_stack *a, int target, int chunks_size)
{
	int	i;
	int	j;

	if (a->top < 2)
		return (0);
	i = a->top;
	while (i >= a->top / 2)
	{
		if (is_in_range(target, chunks_size, a->data[i]))
			break ;
		i--;
	}
	j = 0;
	while (j <= a->top / 2)
	{
		if (is_in_range(target, chunks_size, a->data[j]))
			break ;
		j++;
	}
	if (a->top - i < j + 1)
		return (a->top - i);
	else
		return (-(j + 1));
}

int	sort_b(t_stack *b, int value)
{
	if (b->top <= 0)
		return (0);
	if (is_maxi(b, value) || is_mini(b, value))
		return (max_top(b));
	return (shift_top(b, value));
}

void	exec_rotates(t_stack *a, t_stack *b, int rota, int rotb)
{
	if (rota > 0 && rotb < 0 && rota >= b->top + rotb + 1)
		rotb = b->top + rotb +1;
	if (rota < 0 && rotb > 0 && - rota >= b->top - rotb + 1)
		rotb = -b->top + rotb -1;
	while (rota > 0 && rotb > 0)
	{
		rr(a, b);
		rota--;
		rotb--;
	}
	while (rota < 0 && rotb < 0)
	{
		rrr(a, b);
		rota++;
		rotb++;
	}
	while (rota-- > 0)
		ra(a);
	while (rota++ < -1)
		rra(a);
	while (rotb-- > 0)
		rb(b);
	while (rotb++ < -1)
		rrb(b);
}

int	set_chunk_size(int size)
{
	int	chunks_size;

	if (size >= 400)
		chunks_size = size / 14;
	else
		chunks_size = size / 6;
	return (chunks_size);
}

void	sort_large_stack(t_stack *a, t_stack *b, int size)
{
	int	chunks_size;
	int	target;
	int	i;
	int	rota;
	int	rotb;

	target = 0;
	chunks_size = set_chunk_size(size);
	i = 0;
	while (i != size)
	{
		rota = rotate_top(a, target, chunks_size);
		if (rota >= 0)
			rotb = sort_b(b, a->data[a->top - rota]);
		else
			rotb = sort_b(b, a->data[-rota - 1]);
		exec_rotates(a, b, rota, rotb);
		pb(a, b);
		i++;
		if (i % chunks_size == 0)
			target += chunks_size;
	}
	exec_rotates(a, b, 0, max_top(b));
	push_back_to_a(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:14:05 by jmader            #+#    #+#             */
/*   Updated: 2024/12/17 15:17:48 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_range(int target, int chunks_size, int comp)
{
	if (comp >= target && comp < target + chunks_size)
		return (1);
	else
		return (0);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	while (b->top > -1)
		pa(b, a);
}

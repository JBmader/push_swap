/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:11:31 by jmader            #+#    #+#             */
/*   Updated: 2024/12/17 15:16:10 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	*data;
	int	top;
}	t_stack;
//Instructions
void	swap(t_stack *stack);
void	push(t_stack *stacksrc, t_stack *stackdst);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
//Print and execute instructions
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);
//Sort large utils
void	push_back_to_a(t_stack *a, t_stack *b);
int		is_in_range(int target, int chunks_size, int comp);
//Sort b utils
int		max_top(t_stack *b);
int		shift_top(t_stack *b, int value);
int		is_mini(t_stack *b, int value);
int		is_maxi(t_stack *b, int value);
//Main functions, parsing, index
void	sort_large_stack(t_stack *stack_a, t_stack *stack_b, int size);
int		*index_values(int *data, int size);
void	ft_free_split(char **split);
int		*valparsarg(int argc, char **argv, char ***arg_vector, int *arg_count);
void	push_swap(int *data_a, int size);
//debug
void	print_stacks(t_stack *a, t_stack *b);
#endif
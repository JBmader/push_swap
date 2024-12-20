/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:56:17 by jmader            #+#    #+#             */
/*   Updated: 2024/12/19 17:39:31 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"

int	*parse_args(int size, char **tab)
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(sizeof(int) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = ft_atoi(tab[size - i - 1]);
		i++;
	}
	res[i] = 0;
	return (res);
}

long	ft_atoi_arg(char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		if (str[i + 1] == '\0')
			return (sign * nbr);
		else if (str[i + 1] < '0' || str[i + 1] > '9')
			return (0);
		i++;
	}
	return (0);
}

int	error_handler(int size, char **tab)
{
	int		i;
	int		j;
	long	value;

	i = 0;
	while (i < size)
	{
		value = ft_atoi_arg(tab[i]);
		if (value == 0 && ft_strncmp(tab[i], "0", 1) != 0)
			return (1);
		if (value > 2147483647 || value < -2147483648)
			return (1);
		j = i + 1;
		while (j < size)
		{
			if (value == ft_atoi_arg(tab[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**process_args(int argc, char **argv, int *arg_count)
{
	char	**arg_vector;

	arg_vector = NULL;
	if (argc == 2)
	{
		arg_vector = ft_split(argv[1], ' ');
		if (!arg_vector)
			return (NULL);
		*arg_count = 0;
		while (arg_vector[*arg_count])
			(*arg_count)++;
	}
	else
	{
		arg_vector = argv + 1;
		*arg_count = argc - 1;
	}
	if (error_handler(*arg_count, arg_vector) == 1)
	{
		if (argc == 2)
			ft_free_split(arg_vector);
		return (NULL);
	}
	return (arg_vector);
}

int	*valparsarg(int argc, char **argv, char ***arg_vector, int *arg_count)
{
	int	*stack_a;

	*arg_vector = process_args(argc, argv, arg_count);
	if (!*arg_vector)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	stack_a = parse_args(*arg_count, *arg_vector);
	if (!stack_a)
	{
		if (argc == 2)
			ft_free_split(*arg_vector);
		write(2, "Error\n", 6);
	}
	return (stack_a);
}

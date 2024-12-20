/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:09:46 by jmader            #+#    #+#             */
/*   Updated: 2024/12/09 14:16:48 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(int argc, char **argv)
{
	char	**arg_vector;
	int		*data_a;
	int		arg_count;

	arg_vector = NULL;
	data_a = NULL;
	arg_count = 0;
	if (argc > 1)
	{
		data_a = valparsarg(argc, argv, &arg_vector, &arg_count);
		if (!data_a)
			return (1);
		data_a = index_values(data_a, arg_count);
		if (!data_a)
			return (1);
		push_swap(data_a, arg_count);
	}
	if (argc == 2)
		ft_free_split(arg_vector);
	free(data_a);
	return (0);
}

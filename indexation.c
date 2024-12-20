/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:44:05 by jbmader           #+#    #+#             */
/*   Updated: 2024/12/17 15:45:10 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

static void	fill_sorted(int *sorted, int *data, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		sorted[i] = data[i];
		i++;
	}
}

static void	fill_indx_data(int *indexed_data, int *data, int *sorted, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (data[i] != sorted[j])
			j++;
		indexed_data[i] = j;
		i++;
	}
}

int	*index_values(int *data, int size)
{
	int	*sorted;
	int	*indexed_data;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		write(2, "Error\n", 6);
		free(data);
		return (NULL);
	}
	indexed_data = malloc(sizeof(int) * size);
	if (!indexed_data)
	{
		write(2, "Error\n", 6);
		free(data);
		free(sorted);
		return (NULL);
	}
	fill_sorted(sorted, data, size);
	sort_array(sorted, size);
	fill_indx_data(indexed_data, data, sorted, size);
	free(data);
	free(sorted);
	return (indexed_data);
}

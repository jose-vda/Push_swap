/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-vda <jose-vda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 07:55:13 by jose-vda          #+#    #+#             */
/*   Updated: 2025/07/11 11:52:30 by jose-vda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	size_bit(int max)
{
	int	bit_size;

	bit_size = 0;
	while ((max >> bit_size) != 0)
		bit_size++;
	return (bit_size);
}

int	max_value(t_stack *a)
{
	t_node	*tmp;
	int		max;

	tmp = a->top;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

void	sort_b(t_stack *a, t_stack *b, int j)
{
	int	b_size;

	b_size = b->size;
	while (b_size--)
	{
		if (((b->top->value >> j) & 1) == 0)
			rb(b);
		else
			pa(a, b);
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	j;
	int	bit_size;
	int	size;

	if (is_sorted(a))
		return ;
	j = 0;
	bit_size = size_bit(max_value(a));
	while (j < bit_size)
	{
		size = a->size;
		while (size--)
		{
			if (((a->top->value >> j) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		sort_b(a, b, j);
		j++;
	}
	while (b->size > 0)
		pa(a, b);
}

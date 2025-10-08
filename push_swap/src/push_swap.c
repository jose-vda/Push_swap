/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-vda <jose-vda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 07:40:23 by jose-vda          #+#    #+#             */
/*   Updated: 2025/07/11 11:46:10 by jose-vda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b, int *values)
{
	free_stack(a);
	free_stack(b);
	free(values);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	push_swap(t_stack *a, t_stack *b, int count)
{
	if (count == 2)
		sort_two(a);
	else if (count == 3)
		sort_three(a);
	else if (count == 4)
		sort_four(a, b);
	else if (count == 5)
		sort_five(a, b);
	else if (count > 5)
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	int		count;
	int		*values;
	int		i;
	t_args	args;

	(void)argv;
	if (argc <= 1)
		return (0);
	args.a = init_stack();
	args.b = init_stack();
	args.argc = argc;
	args.argv = argv;
	if (!args.a || !args.b)
		print_error_and_exit(args.a, args.b);
	values = parse_args(args, &count);
	i = 0;
	while (i < count)
		push_stack(args.a, values[i++]);
	push_swap(args.a, args.b, count);
	free_stack(args.a);
	free_stack(args.b);
	free(values);
	return (0);
}

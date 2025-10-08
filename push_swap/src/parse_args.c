/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-vda <jose-vda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 07:42:19 by jose-vda          #+#    #+#             */
/*   Updated: 2025/07/11 10:04:17 by jose-vda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicate(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	*normalize(int *values, int size)
{
	int	*new;
	int	i;
	int	j;

	new = malloc(sizeof(int) * (size + 1));
	if (!new)
		return (values);
	i = 0;
	while (i < size)
	{
		j = 0;
		new[i] = 0;
		while (j < size)
		{
			if (values[i] > values[j])
				new[i]++;
			j++;
		}
		i++;
	}
	free(values);
	return (new);
}

int	*parse_args(t_args args, int *count)
{
	long int	num;
	int			*array;
	int			i;
	int			size;

	array = malloc(sizeof(int) * INT_MAX);
	if (!array)
		print_error_and_exit(args.a, args.b);
	i = 1;
	size = 0;
	while (i < args.argc)
	{
		if (!is_number(args.argv[i]))
			free_all(args.a, args.b, array);
		num = ft_atol(args.argv[i++]);
		if (num > INT_MAX || num < INT_MIN)
			free_all(args.a, args.b, array);
		array[size++] = num;
	}
	if (has_duplicate(array, args.argc - 1))
		free_all(args.a, args.b, array);
	*count = size;
	return (normalize(array, size));
}

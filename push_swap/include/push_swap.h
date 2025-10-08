/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-vda <jose-vda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 07:41:13 by jose-vda          #+#    #+#             */
/*   Updated: 2025/07/10 12:22:04 by jose-vda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*end;
	int				size;
	struct s_stack	*next;
}					t_stack;

typedef struct s_args
{
	t_stack			*a;
	t_stack			*b;
	int				argc;
	char			**argv;
}					t_args;

void				free_all(t_stack *a, t_stack *b, int *values);
void				push_swap(t_stack *a, t_stack *b, int count);

int					*parse_args(t_args args, int *count);
void				print_error_and_exit(t_stack *a, t_stack *b);

t_stack				*init_stack(void);
void				push_stack(t_stack *stack, int value);
void				free_stack(t_stack *stack);

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

int					is_sorted(t_stack *a);
void				sort_two(t_stack *a);
void				sort_three(t_stack *a);
int					find_min_position(t_stack *stack);
void				push_min_to_b(t_stack *a, t_stack *b);
void				sort_four(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);
void				radix_sort(t_stack *a, t_stack *b);
void				assign_indices(t_stack *a);

#endif

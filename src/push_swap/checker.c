/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:51:52 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/04 12:06:35 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_space(char c)
{
	if ((unsigned char)c == 32)
		return (1);
	else if ((unsigned char)c >= 9 && (unsigned char)c <= 13)
		return (1);
	return (0);
}

int	strict_atoi(char *str, int *is_ok)
{
	int	r;	
	int	fat;

	r = 0;
	fat = 1;
	*is_ok = 1;
	if (*str)
	{
		while (is_space(*str))
			str++;
		if (*str == 43 || *str == 45)
			if (*str++ == 45)
				fat = -1;
		while (*str)
		{
			r = r * 10 + (*str++ - 48);
			if (*str != 0 && (*str < 46 || *str > 56))
			{
				*is_ok = 0;
				return 0;
			}
		}
		return (r * fat);
	}
	*is_ok = 0;
	return (0);
}

t_stack	new_stack(int size)
{
	t_stack	stack;

	if (size < 1)
		stack.size = 1;
	else
		stack.size = size;
	stack.stack = NULL;
	stack.stack = ft_calloc(stack.size, sizeof(int *));
	stack.top = -1;
	return (stack);
}

void	destroy_stack(t_stack *stack)
{
	if (stack->stack)
		free(stack->stack);
	stack->stack = NULL;
	stack->top = -1;
	stack->size = 0;
}

int		push_to_stack(t_stack	*stack, int element)
{
	stack->top++;
	if (stack->top < stack->size)
		stack->stack[stack->top] = element;
	else
	{
		stack->top--;
		return (0);
	}
	return (1);
}

int		pop_from_stack(t_stack	*stack)
{
	if (stack->stack != NULL)
	{
		if (stack->top > -1)
		{
			stack->stack[stack->top] = 0;
			stack->top--;
		}
		return (1);
	}
	return (0);
}

void	swap_int(int *a, int *b)
{
	int	buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

void	swap_stack_top(t_stack *stack)
{
	int	buf;

	if (stack->size > 1 && stack->top > 0)
	{
		swap_int(&stack->stack[stack->top], &stack->stack[stack->top - 1]);
	}
}

void	shift_stack(t_stack *stack)
{
	int	buf;
	int	i;

	i = stack->top;
	buf = stack->stack[i];
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[i] = buf;
}

void	reverse_shift_stack(t_stack *stack)
{
	int	buf;
	int	i;

	i = 0;
	buf = stack->stack[i];
	while (i < stack->top)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[stack->top] = buf;
}

void	stack_shifter(t_stack *stack, int direction)
{
	if (stack->top > 1)
	{
		if (direction > 0)
			shift_stack(stack);
		else if (direction < 0)
			reverse_shift_stack(stack);
	}
}

t_stack	parse_input(int argc, char *argv[])
{
	t_stack	stack;
	int		is_ok;

	if (argc == 1)
	{
		ft_putstr_fd("At least one argument must be provided.\n", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		argc--;
		stack = new_stack(argc);
		while (argc >= 1)
		{
			push_to_stack(&stack, strict_atoi(argv[argc], &is_ok));
			if (!is_ok)
			{
				destroy_stack(&stack);
				ft_putstr_fd("Error: The argument[", 2);
				ft_putstr_fd("] is invalid.\n", 2);
				exit(EXIT_FAILURE);
			}
			argc--;
		}
	}
}

void	sa(t_p_swap *state)
{
	swap_stack_top(&state->a);
}

void	sb(t_p_swap *state)
{
	swap_stack_top(&state->b);
}

void	ss(t_p_swap *state)
{
	swap_stack_top(&state->a);
	swap_stack_top(&state->b);
}

void	pa(t_p_swap *state)
{
	int	temp;

	if (state->b.top > -1)
	{
		temp = state->b.stack[state->b.top];
		pop_from_stack(&state->b);
		push_to_stack(&state->a, temp);
	}
}

void	pb(t_p_swap *state)
{
	int	temp;

	if (state->a.top > -1)
	{
		temp = state->a.stack[state->a.top];
		pop_from_stack(&state->a);
		push_to_stack(&state->b, temp);
	}
}

void	ra(t_p_swap *state)
{
	shift_stack(&state->a);
}

void	rb(t_p_swap *state)
{
	shift_stack(&state->b);
}

void	rr(t_p_swap *state)
{
	shift_stack(&state->a);
	shift_stack(&state->b);
}

void	rra(t_p_swap *state)
{
	reverse_shift_stack(&state->a);
}

void	rrb(t_p_swap *state)
{
	reverse_shift_stack(&state->b);
}

void	rrr(t_p_swap *state)
{
	reverse_shift_stack(&state->a);
	reverse_shift_stack(&state->b);
}

int	main(int argc, char *argv[])
{
	int			argc_i;
	int			is_ok;
	int			buf;
	t_p_swap	state;

	if (argc == 1)
	{
		ft_putstr_fd("At least one argument must be provided.\n", 1);
		return (0);
	}
	else
	{
		argc_i = argc - 1;
		state.a = new_stack(argc_i);
		while (argc_i >= 1)
		{
			buf = strict_atoi(argv[argc_i], &is_ok);
			push_to_stack(&state.a, buf);
			argc_i--;
		}
		stack_shifter(&state.a, 1);
		stack_shifter(&state.a, 1);
		stack_shifter(&state.a, -1);
		stack_shifter(&state.a, -1);
		while (state.a.top > -1)
			pop_from_stack(&state.a);
		destroy_stack( &state.a);
	}
	return (0);
}

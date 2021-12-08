/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:57:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/08 20:26:53 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char *argv[])
{
	t_p_swap	state;

	state = new_state_from_input(argc, argv);
	if (!stack_is_sorted(state.a))
	{
		if (state.a.size == 2)
			sort_two_sized_stack(&state);
		else if (state.a.size == 3)
			sort_three_sized_stack(&state);
		else if (state.a.size == 4)
			sort_four_sized(&state);
		else if (state.a.size == 5)
			sort_five_sized(&state);
		else if (state.a.size > 3)
			quick_selection(&state);
		rotate_as_needed(&state);
		optmize_op_list(state.operations, &state.operations);
		print_op_list(state.operations);
	}
	destroy_state(&state);
	return (0);
}

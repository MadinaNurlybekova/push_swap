/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:17:10 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/29 20:47:39 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	instructions_two(const char *instr, t_list **stack_a, t_list **stack_b)
{
	if (instr[0] == 's' && instr[2] == '\n')
	{
		if (instr[1] == 'a')
			b_sa(stack_a);
		else if (instr[1] == 'b')
			b_sb(stack_b);
		else if (instr[1] == 's')
			b_ss(stack_a, stack_b);
	}
	else if (instr[0] == 'p' && instr[2] == '\n')
	{
		if (instr[1] == 'a')
			b_pa(stack_a, stack_b);
		else if (instr[1] == 'b')
			b_pb(stack_a, stack_b);
	}
}

void	instructions_one(const char *instr, t_list **stack_a, t_list **stack_b)
{
	if (instr[0] == 'r' && instr[2] == '\n')
	{
		if (instr[1] == 'a')
			b_ra(stack_a);
		else if (instr[1] == 'b')
			b_rb(stack_b);
		else if (instr[1] == 'r')
			b_rr(stack_a, stack_b);
	}
	else if (instr[0] == 'r' && instr[1] == 'r' && instr[3] == '\n')
	{
		if (instr[2] == 'a')
			b_rra(stack_a);
		else if (instr[2] == 'b')
			b_rrb(stack_b);
		else if (instr[2] == 'r')
			b_rrr(stack_a, stack_b);
	}
	else if ((instr[0] == 's' || instr[0] == 'p') && instr[2] == '\n')
		instructions_two(instr, stack_a, stack_b);
	else
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

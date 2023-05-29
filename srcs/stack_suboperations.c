/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_suboperations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:47:35 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/25 21:48:36 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*  do rr * score_a and rb * (score_b - score_a)
	or
	do rr * score_b and ra * (score_a - score_b) */
void	submove_rr(int score_a, int score_b, t_list **stack_a, t_list **stack_b)
{
		if (score_a <= score_b)
		{
			score_b -= score_a;
			while (score_a-- != 0)
				rr(stack_a, stack_b);
			while (score_b-- != 0)
				rb(stack_b);
		}
		else if (score_b < score_a)
		{
			score_a -= score_b;
			while (score_b-- != 0)
				rr(stack_a, stack_b);
			while (score_a-- != 0)
				ra(stack_a);
		}
}

/*  do rrr * score_a and rrb * (score_b - score_a)
	or
	do rrr * score_b and rra * (score_a - score_b) */
void	submove_rrr(int score_a, int score_b, t_list **stack_a, t_list **stack_b)
{
		if (score_a <= score_b)
		{
			score_b -= score_a;
			while (score_a-- != 0)
				rrr(stack_a, stack_b);
			while (score_b-- != 0)
				rrb(stack_b);
		}
		else if (score_b < score_a)
		{
			score_a -= score_b;
			while (score_b-- != 0)
				rrr(stack_a, stack_b);
			while (score_a-- != 0)
				rra(stack_a);
		}
}

/*	do ra * score_a
	do rrb * score_b */
void	submove_rarrb(int score_a, int score_b, t_list **stack_a, t_list **stack_b)
{
		while (score_a-- != 0)
			ra(stack_a);
		while (score_b-- != 0)
			rrb(stack_b);
}

/*	do rra * scora_a
	do rb * score_b */
void	submove_rbrra(int score_a, int score_b, t_list **stack_a, t_list **stack_b)
{
		while (score_a-- != 0)
			rra(stack_a);
		while (score_b-- != 0)
			rb(stack_b);
}

/* this function pushes first 2 elem of stack A to stack B as a starting point for sorting.
And sorts stack_b in descending order if needed */
void pb_two_elem(t_list **stack_a, t_list **stack_b)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
	if ((*stack_b)->data < (*stack_b)->next->data)
		sb(stack_b);
}
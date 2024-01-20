/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienmoigno <julienmoigno@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:53:54 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/01/20 17:32:58 by julienmoign      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* this function gets the future index of the elem 
in another stack in order to calculated the score */
int	get_future_index_in_b(int num, t_list *stack_b)
{
	int future_index;

	if (num < min_value(stack_b) || num > max_value(stack_b))
		future_index = get_max_elem(stack_b)->index;
	else
	{
		future_index = 1;
		if (num < get_last_elem(stack_b)->data && num > stack_b->data)
			future_index = 0;
		else
		{
			while (stack_b->next != NULL 
				&& !(num < stack_b->data && num > stack_b->next->data))
			{
				future_index++;
				stack_b = stack_b->next; 
			}
		}
	}
	return (future_index);
}

/* this function assigns the score value to each of the node->score */
void get_score_ab(t_list **stack_a, t_list **stack_b)
{
	t_list *elem;
	int future_index;

	elem = *stack_a;
	while (elem != NULL)
	{
		future_index = get_future_index_in_b(elem->data, *stack_b);
		elem->score = calculate_score(elem, *stack_a, *stack_b, future_index);
		if (elem->score == 1)
			break ;
		elem = elem->next;
	}
}

int	get_score_a(t_list *elem, t_list *stack_a)
{
	int score;

	score = 0;

	if (elem->index < get_mid_list(stack_a))
		score += elem->index;
	else
		score += ft_lstsize(stack_a) - elem->index;

	return (score);
}

int get_score_b(t_list *stack_b, int future_index)
{
	int score;

	score = 0;

	if (future_index < get_mid_list(stack_b))
		score += future_index;
	else 
		score += ft_lstsize(stack_b) - future_index;

	return (score);
}


void	move_a_to_b(t_list **stack_a, t_list **stack_b, t_list *elem)
{
	int score_a;
	int score_b;
	int future_index;

	future_index = get_future_index_in_b(elem->data, *stack_b);
	score_a = get_score_a(elem, *stack_a);
	score_b = get_score_b(*stack_b, future_index);
	if (elem->index < get_mid_list(*stack_a) 
		&& future_index < get_mid_list(*stack_b))
		submove_rr(score_a, score_b, stack_a, stack_b);
	else if (elem->index >= get_mid_list(*stack_a) 
		&& future_index >= get_mid_list(*stack_b))
		submove_rrr(score_a, score_b, stack_a, stack_b);
	else if (elem->index < get_mid_list(*stack_a) 
		&& future_index >= get_mid_list(*stack_b))
		submove_rarrb(score_a, score_b, stack_a, stack_b);
	else if (elem->index >= get_mid_list(*stack_a) 
		&& future_index < get_mid_list(*stack_b))
		submove_rbrra(score_a, score_b, stack_a, stack_b);
	pb(stack_a, stack_b);
}
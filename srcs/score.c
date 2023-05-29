/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:57:02 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/25 22:05:28 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* this function calculates score of each elem in stack and returns the score value */
int calculate_score(t_list *elem_a, t_list *stack_a, t_list *stack_b, int future_index)
{
	int score_a;
	int score_b;
	
	score_a = 0;
	score_b = 0;
	if (elem_a->index < get_mid_list(stack_a))
		score_a += elem_a->index;
	else
		score_a += ft_lstsize(stack_a) - elem_a->index; 
	if (future_index < get_mid_list(stack_b))
		score_b += future_index;
	else 
		score_b += ft_lstsize(stack_b) - future_index;
	if (((elem_a->index < get_mid_list(stack_a) && future_index < get_mid_list(stack_b))
			|| (elem_a->index >= get_mid_list(stack_a) && future_index >= get_mid_list(stack_b)))
			&& score_a != 0 && score_b != 0)
		{
			if (score_a <= score_b)
				score_a = 0;
			else if (score_b < score_a)
				score_b = 0;
		}
	return (score_a + score_b + 1);
}
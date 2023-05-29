/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:47:42 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/25 22:07:33 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "../libft/ft_lstadd_back.c"
// #include "../libft/ft_lstadd_front.c"
// #include "../libft/ft_lstnew.c"
// #include "../libft/ft_lstsize.c"
// #include "../libft/ft_atoi.c"
// #include "stack_operations_a.c"
// #include "stack_operations_b.c"
// #include "stack_operations_ab.c"
// #include "small_sort.c"
// #include "min_max_value.c"
// #include "get_index.c"
// #include "big_sort.c"

/* this function gets the future index of the elem in another stack in order to calculated the score */
int	get_future_index_in_a(int num, t_list *stack_a)
{
	int future_index;

	if (num < min_value(stack_a) || num > max_value(stack_a))
		future_index = get_min_elem(stack_a)->index;
	else
	{
		future_index = 1;
		if (num > get_last_elem(stack_a)->data && num < stack_a->data)
			future_index = 0;
		else
		{
			while (stack_a->next != NULL && !(num > stack_a->data && num < stack_a->next->data))
			{
				future_index++;
				stack_a = stack_a->next; 
			}
		}
	}
	return (future_index);
}

/* this function assigns the score value to each of the node->score */
void get_score_ba(t_list **stack_a, t_list **stack_b)
{
	t_list *elem;
	int future_index;

	elem = *stack_b;
	while (elem != NULL)
	{
		future_index = get_future_index_in_a(elem->data, *stack_a);
		elem->score = calculate_score(elem, *stack_b, *stack_a, future_index);
		if (elem->score == 1)
			break ;
		elem = elem->next;
	}
}

void	move_b_to_a(t_list **stack_b, t_list **stack_a, t_list *elem)
{
	int score_a;
	int score_b;
	int future_index;

	score_a = 0;
	score_b = 0;
	future_index = get_future_index_in_a(elem->data, *stack_a);
	if (elem->index < get_mid_list(*stack_b))
		score_b += elem->index;
	else
		score_b += ft_lstsize(*stack_b) - elem->index; 
	if (future_index < get_mid_list(*stack_a))
		score_a += future_index;
	else 
		score_a += ft_lstsize(*stack_a) - future_index;
	if (elem->index < get_mid_list(*stack_b) && future_index < get_mid_list(*stack_a))
		submove_rr(score_a, score_b, stack_a, stack_b);
	else if (elem->index >= get_mid_list(*stack_b) && future_index >= get_mid_list(*stack_a))
		submove_rrr(score_a, score_b, stack_a, stack_b);
	else if (elem->index < get_mid_list(*stack_b) && future_index >= get_mid_list(*stack_a))
		submove_rbrra(score_a, score_b, stack_a, stack_b);
	else if (elem->index >= get_mid_list(*stack_b) && future_index < get_mid_list(*stack_a))
		submove_rarrb(score_a, score_b, stack_a, stack_b);
	pa(stack_a, stack_b);
}


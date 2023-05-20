/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:59:28 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/20 23:23:18 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/ft_lstadd_back.c"
#include "../libft/ft_lstadd_front.c"
#include "../libft/ft_lstnew.c"
#include "../libft/ft_lstsize.c"
#include "../libft/ft_atoi.c"
#include "stack_operations_a.c"
#include "stack_operations_b.c"
#include "stack_operations_ab.c"
#include "small_sort.c"
#include "min_max_value.c"
#include "get_index.c"
// #include "move_ab.c"

void	print(t_list *list)
{
	while (list != NULL)
	{
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

void	print_details(t_list *list)
{
	while (list != NULL)
	{
		printf("data: %d, index: %d, score: %d\n", list->data, list->index, list->score);
		list = list->next;
	}
	printf("\n");
}

/* This function initializes the index 
and the score of each node in the stack, cause after we moved one element 
we need to refresh the indexes and score according to the changed stack data */
void init_elem_data_ab(t_list *stack)
{
    t_list *elem;
    int i;

    elem = stack;
    i = 0; 
    while (elem != NULL)
    {
        elem->index = i;
        elem->score = 0;
        elem = elem->next;
        i++;
    }
}

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

/* this function returns the pointer to the node with the max value in a stack */
t_list	*get_max_elem(t_list *stack)
{
	t_list *elem_b;
	
	elem_b = stack;
	while (elem_b != NULL)
	{
		if (elem_b->data == max_value(stack))
			break;
		elem_b = elem_b->next;
	}
	return (elem_b);
}

/* this function returns the pointer to the node with the min value in a stack */
t_list	*get_min_elem(t_list *stack)
{
	t_list *elem_b;
	
	elem_b = stack;
	while (elem_b != NULL)
	{
		if (elem_b->data == min_value(stack))
			break;
		elem_b = elem_b->next;
	}
	return (elem_b);
}

/* this function gets the future index of the elem in another stack in order to calculated the score */
int	get_future_index_in_b(int num, t_list *stack_b)
{
	t_list *elem_b;
	int future_index;

	elem_b = stack_b;
	if (num < min_value(stack_b) || num > max_value(stack_b))
		future_index = get_max_elem(stack_b)->index;
	else
	{
		future_index = 1;
		if (num < get_last_elem(stack_b)->data && num > stack_b->data)
			future_index = 0;
		else
		{
			while (stack_b->next != NULL && !(num < stack_b->data && num > stack_b->next->data))
			{
				future_index++;
				stack_b = stack_b->next; 
			}
		}
	}
	return (future_index);
}

/* this function assigns the score value to each of the node->score */
void get_score(t_list **stack_a, t_list **stack_b)
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

/* this function finds and returns the elem with the lowest score, 
meaning that it would be the cheapest element to push */
t_list	*get_cheapest_elem(t_list *stack)
{
	t_list *cheap_elem;

	cheap_elem = stack; 
	while (stack != NULL)
	{
		if (stack->score == 1)
		{
			cheap_elem = stack;
			break ; 
		}
		if (stack->score < cheap_elem->score)
			cheap_elem = stack;
		stack = stack->next;
	}
	return (cheap_elem);
}

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

void	move_a_to_b(t_list **stack_a, t_list **stack_b, t_list *elem)
{
	int score_a;
	int score_b;
	int future_index;

	score_a = 0;
	score_b = 0;
	future_index = get_future_index_in_b(elem->data, *stack_b);
	if (elem->index < get_mid_list(*stack_a))
		score_a += elem->index;
	else
		score_a += ft_lstsize(*stack_a) - elem->index; 
	if (future_index < get_mid_list(*stack_b))
		score_b += future_index;
	else 
		score_b += ft_lstsize(*stack_b) - future_index;
	if (elem->index < get_mid_list(*stack_a) && future_index < get_mid_list(*stack_b))
		submove_rr(score_a, score_b, stack_a, stack_b);
	else if (elem->index >= get_mid_list(*stack_a) && future_index >= get_mid_list(*stack_b))
		submove_rrr(score_a, score_b, stack_a, stack_b);
	else if (elem->index < get_mid_list(*stack_a) && future_index >= get_mid_list(*stack_b))
		submove_rarrb(score_a, score_b, stack_a, stack_b);
	else if (elem->index >= get_mid_list(*stack_a) && future_index < get_mid_list(*stack_b))
		submove_rbrra(score_a, score_b, stack_a, stack_b);
	pb(stack_a, stack_b);
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

void big_sort(t_list **stack_a, t_list **stack_b)
{
	t_list *cheap_elem;
	if (!check_if_sorted(*stack_a))
		return ;
	// 1. move from A to B;
    pb_two_elem(stack_a, stack_b);
	while (ft_lstsize(*stack_a) != 3)
	{		
		init_elem_data_ab(*stack_a);
		init_elem_data_ab(*stack_b);
		get_score(stack_a, stack_b);
		cheap_elem = get_cheapest_elem(*stack_a);
		move_a_to_b(stack_a, stack_b, cheap_elem);
	}

	// 2.sort three A
	if (check_if_sorted(*stack_a))
		sort_three(stack_a);

	// 3. Move from B to A
	init_elem_data_ab(*stack_a);
	init_elem_data_ab(*stack_b);
	
	// 4. Rotate A until sorted
	
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	t_list	*node;

	stack_a = NULL;
	stack_b = NULL;	
	i = 1;
	while (i < argc)
	{
		node = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	printf("\nBefore STACK_A: ");
	print(stack_a);
	printf("\nBefore STACK_B: ");
	print(stack_b);
	
	big_sort(&stack_a, &stack_b);
	
	printf("\n After STACK_A: ");
	print(stack_a);
	printf("\n");
	print_details(stack_a);
	
	printf("\n After STACK_B: ");
	print(stack_b);
	printf("\n");
	print_details(stack_b);
    
	return (0);
}

/* plan for another session: 
	1. clean up the big sort file (norminette, and make unviersal functions if it is possible)
	2. code step 3 - move B to A
	3. code/add step 4
	4. final clean up
	5. create checker
*/

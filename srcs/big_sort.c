/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:59:28 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/29 20:57:13 by mnurlybe         ###   ########.fr       */
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
// #include "stack_oper_adds.c"
// #include "small_sort.c"
// #include "min_max_value.c"
// #include "get_index.c"
// #include "move_b_to_a.c"
// #include "stack_suboperations.c"

// void	print(t_list *list)
// {
// 	while (list != NULL)
// 	{
// 		printf("%d ", list->data);
// 		list = list->next;
// 	}
// 	printf("\n");
// }

// void	print_details(t_list *list)
// {
// 	while (list != NULL)
// 	{
// 		printf("data: %d, index: %d, score: %d\n", list->data, list->index, list->score);
// 		list = list->next;
// 	}
// 	printf("\n");
// }

/* This function initializes the index 
and the score of each node in the stack, cause after we moved one element 
we need to refresh the indexes and score according to the changed stack data */
void init_elem_data(t_list *stack)
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

void big_sort(t_list **stack_a, t_list **stack_b)
{
	t_list *cheap_elem;
	if (!check_if_sorted(*stack_a))
		return ;
	// 1. move from A to B;
    pb_two_elem(stack_a, stack_b);
	while (ft_lstsize(*stack_a) != 3)
	{		
		init_elem_data(*stack_a);
		init_elem_data(*stack_b);
		get_score_ab(stack_a, stack_b);
		cheap_elem = get_cheapest_elem(*stack_a);
		move_a_to_b(stack_a, stack_b, cheap_elem);
	}

	// 2.sort three A
	if (check_if_sorted(*stack_a))	// printf("{CHEAP_ELEM: %d, %d}", cheap_elem->data, cheap_elem->score);
		sort_three(stack_a);

	// 3. Move from B to A
	while (ft_lstsize(*stack_b) != 0)
	{		
		init_elem_data(*stack_a);
		init_elem_data(*stack_b);
		get_score_ba(stack_a, stack_b);
		cheap_elem = get_cheapest_elem(*stack_b);
		move_b_to_a(stack_b, stack_a, cheap_elem);
	}
	
	// 4. Rotate A until sorted
	finalize_stack_a(stack_a);

	// if (check_if_sorted(*stack_a) == 0)
	// 	printf("stack A is sorted");
	// else if (check_if_sorted(*stack_a) == 1)
	// 	printf("stack A is NOT sorted");
}

// int main(int argc, char **argv)
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;
// 	int		i;
// 	t_list	*node;

// 	stack_a = NULL;
// 	stack_b = NULL;	
// 	i = 1;
// 	while (i < argc)
// 	{
// 		node = ft_lstnew(ft_atoi(argv[i]));
// 		ft_lstadd_back(&stack_a, node);
// 		i++;
// 	}
// 	// printf("\nBefore STACK_A: ");
// 	// print(stack_a);
// 	// printf("\nBefore STACK_B: ");
// 	// print(stack_b);
	
// 	big_sort(&stack_a, &stack_b);
	
// 	// printf("\n After STACK_A: ");
// 	// print(stack_a);
// 	// printf("\n");
// 	// print_details(stack_a);
	
// 	// printf("\n After STACK_B: ");
// 	// print(stack_b);
// 	// printf("\n");
// 	// print_details(stack_b);
    
// 	return (0);
// }

/* plan for another session: 
	1. clean up the big sort file (norminette, and make unviersal functions if it is possible)
	2. code step 3 - move B to A
	3. code/add step 4
	4. final clean up
	5. create checker
	6. add condition check if stack it sorted or not
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:03:03 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/25 22:05:02 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "../libft/ft_lstadd_back.c"
// #include "../libft/ft_lstadd_front.c"
// #include "../libft/ft_lstnew.c"
// #include "../libft/ft_atoi.c"
// #include "../libft/ft_lstsize.c"
// #include "stack_operations_a.c"
// #include "stack_operations_b.c"
// #include "stack_operations_ab.c"
// #include "small_sort.c"
// #include "min_max_value.c"

// void	print(t_list *list)
// {
// 	while (list != NULL)
// 	{	// printf("{CHEAP_ELEM: %d, %d}", cheap_elem->data, cheap_elem->score);
// 		printf("%d ", list->data);
// 		list = list->next;
// 	}
// 	printf("\n");
// }

/* this function checks if stack is sorted in descending 
order (used only for stack_b that has only 1-2 elements) */
int	check_if_b_sorted(t_list *stack)
{
	t_list	*elem;

	elem = stack;
	if (ft_lstsize(elem) == 1)
		return (0);
	while (elem->next != NULL)
	{
		if (elem->data < elem->next->data)
			return (1);
		elem = elem->next;
	}
	return (0);
}

/* this function push the elem from 
STACK_B to STACK_A after both stacks got sorted */
void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int		pos_before;
	t_list	*elem;

	while (ft_lstsize(*stack_b) != 0)
	{
		elem = *stack_a;
		if ((*stack_b)->data < min_value(*stack_a)
			|| (*stack_b)->data > max_value(*stack_a))
		{
			while ((*stack_a)->data != min_value(*stack_a))
				ra(stack_a);
		}
		else if ((*stack_b)->data > min_value(*stack_a)
			&& (*stack_b)->data < max_value(*stack_a))
		{
			if (!((*stack_b)->data > get_last_elem(*stack_a)->data
					&& (*stack_b)->data < (*stack_a)->data))
			{
				pos_before = get_index_before(elem, *stack_b);
				stack_rotation(pos_before, stack_a);
			}
		}
		pa(stack_a, stack_b);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (!check_if_sorted(*stack_a))
		return ;
	while (ft_lstsize(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (check_if_sorted(*stack_a))
		sort_three(stack_a);
	if (check_if_b_sorted(*stack_b))
		sb(stack_b);
	push_to_a(stack_a, stack_b);
	finalize_stack_a(stack_a);
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
// 	printf("Before:\n");
// 	printf("a: ");
// 	print(stack_a);
// 	printf("\nb: ");
// 	print(stack_b);
// 	sort_five(&stack_a, &stack_b);
// 	printf("\nAfter:\n");
// 	printf("a: ");
// 	print(stack_a);
// 	printf("\nb: ");
// 	print(stack_b);
// 	return (0);
// }
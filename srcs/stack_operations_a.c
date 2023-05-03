/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:20:24 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/03 20:22:20 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
void sa(t_list **stack)
{
    t_list *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    // tmp = (*stack)->data;
    // (*stack)->data= (*stack)->next->data;
    // (*stack)->next->data = tmp;

    // alternative method without swaping the data
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
    
    // write(1, "sa\n", 3);
}

/*pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/
void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (!*stack_b)
        return ;
        
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    
    if (!*stack_a)
        ft_lstadd_back(stack_a, tmp);
    else
        ft_lstadd_front(stack_a, tmp);

    // write(1, "pb\n", 3);
}

/*ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
void ra(t_list **stack)
{
    t_list *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    ft_lstadd_back(stack, tmp);

    // write(1, "ra\n", 3);
}

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one*/
void rra(t_list **stack)
{
    t_list *tmp;
    t_list *last;

    tmp = *stack;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    last->next = *stack;
    *stack = last; 
      
    // write(1, "rra\n", 3);
}


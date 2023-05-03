/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:22:31 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/03 20:24:04 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
void sb(t_list **stack)
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
    
    // write(1, "sb\n", 3);
}

/*pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (!*stack_a)
        return ;
        
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    
    if (!*stack_b)
        ft_lstadd_back(stack_b, tmp);
    else
        ft_lstadd_front(stack_b, tmp);

    // write(1, "pb\n", 3);
}

/*rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
void rb(t_list **stack)
{
    t_list *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    ft_lstadd_back(stack, tmp);

    // write(1, "rb\n", 3);
}

/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
void rrb(t_list **stack)
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
      
    // write(1, "rrb\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:19:15 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/25 21:51:40 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int max_value(t_list *stack)
{
    t_list *elem;
    int max;

    elem = stack;
    max = stack->data;
    while (elem != NULL)
    {
        if (elem->data > max)
            max = elem->data;
        elem = elem->next;
    }
    return (max);
}

int min_value(t_list *stack)
{
    t_list *elem;
    int min;

    elem = stack;
    min = stack->data;
    while (elem != NULL)
    {
        if (elem->data < min)
            min = elem->data;
        elem = elem->next;
    }
    return (min);
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
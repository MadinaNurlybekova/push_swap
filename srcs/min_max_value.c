/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:19:15 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/16 19:20:48 by mnurlybe         ###   ########.fr       */
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
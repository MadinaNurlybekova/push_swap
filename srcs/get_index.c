/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:27:00 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/20 18:07:24 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* this function returns the index of the middle of the list, 
the result will be used to define in which direction rotation will happen */
int	get_mid_list(t_list *stack)
{
	int	res;

	if (ft_lstsize(stack) % 2 == 0)
		res = ft_lstsize(stack) / 2;
	else
		res = (ft_lstsize(stack) / 2) + 1;
	return (res);
}

/* this function returns the last node of the list */
t_list	*get_last_elem(t_list *stack)
{
	t_list	*x;

	x = stack;
	while (x->next != NULL)
		x = x->next;
	return (x);
}

/* this function get the before position where the elem should be */
int	get_index_before(t_list *elem, t_list *stack)
{
	int	pos_before;

	pos_before = 1;
	while (!((stack)->data > (elem)->data
			&& (stack)->data < (elem)->next->data) && (elem)->next != NULL)
	{
		pos_before++;
		(elem) = (elem)->next;
	}
	return (pos_before);
}
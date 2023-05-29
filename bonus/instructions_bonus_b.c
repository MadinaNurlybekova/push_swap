/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:10:21 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/29 20:43:59 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	b_sb(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	b_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (!*stack_b)
		ft_lstadd_back(stack_b, tmp);
	else
		ft_lstadd_front(stack_b, tmp);
}

void	b_rb(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp);
}

void	b_rrb(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
}

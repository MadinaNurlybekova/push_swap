/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus_ab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:13:10 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/29 20:43:43 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	b_ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b) == NULL)
		return ;
	tmp_a = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp_a->next = (*stack_a)->next;
	(*stack_a)->next = tmp_a;
	tmp_b = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp_b->next = (*stack_b)->next;
	(*stack_b)->next = tmp_b;
}

void	b_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b) == NULL)
		return ;
	tmp_a = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_back(stack_a, tmp_a);
	tmp_b = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_back(stack_b, tmp_b);
}

void	b_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*last_a;
	t_list	*last_b;

	if (!(*stack_a) || !((*stack_a)->next) || !(*stack_b)
		|| !((*stack_b)->next))
		return ;
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a->next->next != NULL)
		tmp_a = tmp_a->next;
	last_a = tmp_a->next;
	tmp_a->next = NULL;
	last_a->next = *stack_a;
	*stack_a = last_a;
	while (tmp_b->next->next != NULL)
		tmp_b = tmp_b->next;
	last_b = tmp_b->next;
	tmp_b->next = NULL;
	last_b->next = *stack_b;
	*stack_b = last_b;
}

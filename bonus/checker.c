/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:19:28 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/29 20:47:17 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bonus_output(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	if (line == NULL && !check_if_sorted(*stack_a))
		write(1, "OK\n", 3);
	else if (line == NULL && check_if_sorted(*stack_a))
		write(1, "KO\n", 3);
	else
	{
		while (line != NULL)
		{
			instructions_one(line, stack_a, stack_b);
			line = get_next_line(0);
		}
		if (stack_b == NULL && !check_if_sorted(*stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}

/* main function receives argv argument */
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc >= 2)
	{
		if (error_check(argc, argv))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		fill_stack_a(&stack_a, argc, argv);
	}
	bonus_output(&stack_a, &stack_b);
	ft_free(&stack_a, &stack_b);
	return (0);
}

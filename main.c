/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:53:48 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/29 20:54:04 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

//print the list for testing purpose
// void print(t_list *list)
// {
//     while (list != NULL)
//     {
//         printf("%d ", list->data);
//         list = list->next;
//     }
//     printf("\n");
// }

// main function receives argv argument
int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))  //If no parameters are specified, the program must not display anything and give the prompt back.
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
    if (ft_lstsize(stack_a) <= 3)
        sort_three(&stack_a);
    else if (ft_lstsize(stack_a) <= 5)
        sort_five(&stack_a, &stack_b);
    else
        big_sort(&stack_a, &stack_b);
    ft_free(&stack_a, &stack_b);
    return (0);
}


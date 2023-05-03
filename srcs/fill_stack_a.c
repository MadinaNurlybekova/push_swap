/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:59:29 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/01 17:34:54 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list  *separate_string(char *argv)
{
    char **temp;
    t_list *a;
    t_list *node;
    int i;

    i = 0;
    a = NULL;
    temp = ft_split(argv, ' ');

    while (temp[i])
    {
        node = ft_lstnew(ft_atoi(temp[i]));
        ft_lstadd_back(&a, node);
        i++;
    }
    ft_free_arr(temp);
    free(temp);
    return(a);
}

/* this function checks if the argc is two or more. If it is two then 
we use split (separate_string) function to separate the integers, and then fills 
the stack_a with the integers received from argv. 
If it is more than two, than just fills the stack_a with integers received */

void	fill_stack_a(t_list **stack_a, int argc, char **argv)
{   
    int i;
    t_list *node;
    
    if (argc == 2)
        *stack_a = separate_string(argv[1]);
    else
    {
        i = 1;
        while (i < argc)
        {
            node = ft_lstnew(ft_atoi(argv[i]));
            ft_lstadd_back(stack_a, node);
            i++;
        }       
    }
}
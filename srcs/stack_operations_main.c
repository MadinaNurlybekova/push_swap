/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_main.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:43:30 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/18 20:06:17 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"
#include "../libft/ft_lstadd_back.c"
#include "../libft/ft_lstnew.c"
#include "../libft/ft_atoi.c"


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

/*ss : sa and sb at the same time.*/
void ss(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp_a;
    t_list *tmp_b;
    
    if (*stack_a == NULL || (*stack_a)->next == NULL || *stack_b == NULL || (*stack_b) == NULL)
        return ;

    tmp_a = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp_a->next = (*stack_a)->next;
    (*stack_a)->next = tmp_a;

    tmp_b = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp_b->next = (*stack_b)->next;
    (*stack_b)->next = tmp_b;
    
    // write(1, "ss\n", 3);
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

    write(1, "ra\n", 3);
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

/*rr : ra and rb at the same time.*/
void rr(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp_a;
    t_list *tmp_b;

    if (*stack_a == NULL || (*stack_a)->next == NULL || *stack_b == NULL || (*stack_b) == NULL)
        return ;
    tmp_a = *stack_a;
    *stack_a = (*stack_a)->next;
    ft_lstadd_back(stack_a, tmp_a);

    tmp_b = *stack_b;
    *stack_b = (*stack_b)->next;
    ft_lstadd_back(stack_b, tmp_b);

    // write(1, "rr\n", 3);
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

/*rrr : rra and rrb at the same time.*/
void rrr(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp_a;
    t_list *tmp_b;
    t_list *last_a;
    t_list *last_b;

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
      
    // write(1, "rrr\n", 3);
}


void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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

void print(t_list *list)
{
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    int i;
    t_list *node;
    
    stack_a = NULL;
    stack_b = NULL;
    
    i = 1;
    while (i < argc)
    {
        node = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(&stack_a, node);
        i++;
    }
    printf("Before:\n");
    printf("a: ");
    print(stack_a);
    printf("\nb: ");
    print(stack_b);
    
    // pb(&stack_a, &stack_b);
    // pb(&stack_a, &stack_b);
    // pb(&stack_a, &stack_b);
    // rrr(&stack_a, &stack_b);
    ra(&stack_a);
    ra(&stack_a);
    // ra(stack_a);

    printf("\nAfter:\n");
    printf("a: ");
    print(stack_a);
    printf("\nb: ");
    print(stack_b);

    return (0);
}

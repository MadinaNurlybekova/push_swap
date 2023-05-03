/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:49:43 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/03 20:26:13 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
    int data;
    struct s_list *next;
}   t_list;

// Functions to work with the lists
t_list	*ft_lstnew(int data);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

// libft functions
int	ft_atoi(const char *nptr);
long	ft_atoi_long(const char *nptr);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

// function to fill stack_a with integers received
void	fill_stack_a(t_list **stack_a, int argc, char **argv);

// function for stack operations
void sa(t_list **stack);
void pa(t_list **stack_a, t_list **stack_b);
void ra(t_list **stack);
void rra(t_list **stack);
void sb(t_list **stack);
void pb(t_list **stack_a, t_list **stack_b);
void rb(t_list **stack);
void rrb(t_list **stack);
void ss(t_list **stack_a, t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);


// functions to check the errors
int error_check(int argc, char **argv);
int digit_check(char *lst);
int dup_check(int argc, char **lst, int flag);
int range_check(char *lst);

// functions to free memory
void    ft_free_list(t_list **stack);
void    ft_free_arr(char **arr);

#endif

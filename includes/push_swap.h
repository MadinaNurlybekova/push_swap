/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:49:43 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/29 20:52:16 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	unsigned int	score;
	struct s_list	*next;
}	t_list;

// Functions to work with the lists from libft
t_list	*ft_lstnew(int data);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

// libft functions
int		ft_atoi(const char *nptr);
long	ft_atoi_long(const char *nptr);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

// GNL functions
char	*get_next_line(int fd);
char	*get_tmp(int fd, char *tmp);
char	*get_line(char *tmp);
char	*clean_tmp(char *tmp);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strchr(char *s, char c);
char	*ft_strjoin(char *tmp, char *buf);

// function to fill stack_a with integers received
void	fill_stack_a(t_list **stack_a, int argc, char **argv);

// function for stack operations
void	sa(t_list **stack);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack);
void	rra(t_list **stack);
void	sb(t_list **stack);
void	pb(t_list **stack_a, t_list **stack_b);
void	rb(t_list **stack);
void	rrb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	b_sa(t_list **stack);
void	b_pa(t_list **stack_a, t_list **stack_b);
void	b_ra(t_list **stack);
void	b_rra(t_list **stack);
void	b_sb(t_list **stack);
void	b_pb(t_list **stack_a, t_list **stack_b);
void	b_rb(t_list **stack);
void	b_rrb(t_list **stack);
void	b_ss(t_list **stack_a, t_list **stack_b);
void	b_rr(t_list **stack_a, t_list **stack_b);
void	b_rrr(t_list **stack_a, t_list **stack_b);

// functions for stack suboperations
void	pb_two_elem(t_list **stack_a, t_list **stack_b);
void	submove_rbrra(int score_a, int score_b,
			t_list **stack_a, t_list **stack_b);
void	submove_rarrb(int score_a, int score_b,
			t_list **stack_a, t_list **stack_b);
void	submove_rrr(int score_a, int score_b,
			t_list **stack_a, t_list **stack_b);
void	submove_rr(int score_a, int score_b,
			t_list **stack_a, t_list **stack_b);

// function for additional stack operations
void	finalize_stack_a(t_list **stack_a);
void	stack_rotation(int index, t_list **stack);
void	move_b_to_a(t_list **stack_b, t_list **stack_a, t_list *elem);
void	move_a_to_b(t_list **stack_a, t_list **stack_b, t_list *elem);
void	init_elem_data(t_list *stack);

// functions to check the errors
int		error_check(int argc, char **argv);
int		digit_check(char *lst);
int		dup_check(int argc, char **lst, int flag);
int		range_check(char *lst);

// functions to free memory
void	ft_free_list(t_list **stack);
void	ft_free_arr(char **arr);
void	ft_free(t_list **stack_a, t_list **stack_b);

// functions to get min and max value, and pointer to node with min_max value
int		max_value(t_list *stack);
int		min_value(t_list *stack);
t_list	*get_max_elem(t_list *stack);
t_list	*get_min_elem(t_list *stack);

// head function to sort the stack
void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b);

// get index functions
int		get_mid_list(t_list *stack_a);
t_list	*get_last_elem(t_list *stack);
int		get_index_before(t_list *elem, t_list *stack_b);

// check if sorted
int		check_if_sorted(t_list *stack);
int		check_if_b_sorted(t_list *stack);

// functions to calculate the score
void	get_score_ba(t_list **stack_a, t_list **stack_b);
int		get_future_index_in_a(int num, t_list *stack_a);
void	get_score_ab(t_list **stack_a, t_list **stack_b);
int		get_future_index_in_b(int num, t_list *stack_b);
int		calculate_score(t_list *elem_a, t_list *stack_a,
			t_list *stack_b, int future_index);

// bonus checker
void	instructions_one(const char *instr, t_list **stack_a, t_list **stack_b);
void	instructions_two(const char *instr, t_list **stack_a, t_list **stack_b);

#endif
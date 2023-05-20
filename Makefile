# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 12:47:34 by mnurlybe          #+#    #+#              #
#    Updated: 2023/05/20 23:22:34 by mnurlybe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MY_SOURCES = main.c \
	libft/ft_atoi.c \
	libft/ft_split.c \
	libft/ft_strlen.c \
	libft/ft_lstnew.c \
	libft/ft_lstadd_back.c \
	libft/ft_lstadd_front.c \
	libft/ft_lstsize.c \
	srcs/fill_stack_a.c \
	srcs/error_main.c \
	srcs/error_checks.c \
	srcs/free_memory.c \
	srcs/stack_operations_a.c \
	srcs/stack_operations_b.c \
	srcs/stack_operations_ab.c \
	srcs/small_sort.c \
	srcs/min_max_value.c \
	srcs/five_sort.c \
	srcs/get_index.c \
	srcs/stack_oper_adds.c \
	srcs/big_sort.c \
	     
CFLAGS = -Wall -Wextra -Werror

MY_HEADER = ./includes/

MY_OBJECTS = $(MY_SOURCES:.c=.o)

.c.o:
	gcc $(CFLAGS) -c -I $(MY_HEADER) $< -o ${<:.c=.o}

$(NAME): $(MY_OBJECTS)
	cc $(CFLAGS) -o $(NAME) $(MY_OBJECTS)

all: $(NAME)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

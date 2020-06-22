/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaragre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 18:14:39 by amaragre          #+#    #+#             */
/*   Updated: 2020/06/21 07:52:11 by amaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./libft/includes/libft.h"
# include <stdio.h>

typedef struct			s_elem
{
	int					num;
	struct s_elem		*next;
	struct s_elem		*prev;
}						t_elem;

typedef struct			s_stack
{
	struct s_elem		*head;
	struct s_elem		*tail;
	size_t				size;
}						t_stack;

typedef struct			s_push_swap
{
	struct s_stack		*a;
	struct s_stack		*b;
	unsigned char		is_sorted;
	int					next_min;
	int					current_mid;
	int					once_sorted;
	int					sort_nub;
}						t_push_swap;





unsigned char			ft_input_validation(int ac, char **av);
t_elem					*ft_newelem(int num);
t_stack					*ft_newstack(void);
void					ft_cleanelem(t_elem **elem);
void					ft_cleanstack(t_stack **stack);
void					ft_addstack(t_elem *elem, t_stack **stack);

void					ft_sa(t_push_swap *ps);
void					ft_sb(t_push_swap *ps);
void					ft_ss(t_push_swap *ps);
void					ft_pa(t_push_swap *ps);
void					ft_pb(t_push_swap *ps);
void					ft_ra(t_push_swap *ps);
void					ft_rb(t_push_swap *ps);
void					ft_rr(t_push_swap *ps);
void					ft_rra(t_push_swap *ps);
void					ft_rrb(t_push_swap *ps);
void					ft_rrr(t_push_swap *ps);

unsigned char			ft_is_sorted(t_push_swap *ps);
void					ft_error(void);
void					prep_sort(t_push_swap *ps);
int						mid_sorting(t_stack *stack);
int						min_mid_a(t_push_swap *ps, int min, int curr_mid);
void					min_num_of_operations(t_stack *stack, t_push_swap *ps, char ch);
void					quick_sort_a(t_push_swap *ps);
void					quick_sort_b(t_push_swap *ps);
int						max_on_the_top_b(t_push_swap *ps);
void					rotate_b(int st, int fh, t_push_swap *ps, int max);
int						max_elem(t_stack *stack);
int						min_elem(t_stack *stack);
void					reading_commands(t_push_swap *ps);
int						min_elem_sort(t_push_swap *ps, int min);
void					small_stack(t_stack *stack, t_push_swap *ps, char ch);
void					from_a_to_b(t_push_swap *ps, int min, int mid);
void					from_b_to_a(t_push_swap *ps);
void					three_rotation_for_a(t_stack *stack, t_push_swap *ps);

void					three_rotation_for_b(t_stack *stack, t_push_swap *ps);

void					start_of_sorting(t_push_swap *ps);

void					ft_clean_av(int ac, char **av);

void					ft_clean_input(int n, char **input);

char					**parse_input(char **av, int i, char **input);

void					ft_make_command(t_push_swap *ps, char *line);

#endif

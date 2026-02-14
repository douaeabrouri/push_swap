/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 04:33:16 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/14 17:09:59 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	int				dir_a;
	int				dir_b;
}	t_stack;

void	error_exit(t_stack **stack);
void	free_stack(t_stack	**stack);
void	free_split(char **numbers);
t_stack	*find_cheapest_in_a(t_stack *a);
void	push_cheapest_to_b(t_stack **a, t_stack **b);
t_stack	*find_target_in_a(t_stack *a, int x, int min);
void	rotate_to_target(t_stack **a, t_stack *target);
void	push_back_to_a(t_stack **a, t_stack **b);
int		find_min_position2(t_stack *stack);
void	push_smallest_to_b(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	rotate_b_once(t_stack **b, int dir);
void	set_cost_and_dir(t_stack *node, int pos, int size, int is_a);
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	update_index(t_stack *stack);
int		is_sorted(t_stack	*stack);
char	**take_arguments(char **argv);
int		is_valid_number(char	*str);
long	ft_atoi(const char *arg);
int		duplicate_number(t_stack *stack, int value);
void	fill_stack(char	**numbers, t_stack	**stack);
int		is_only_spaces(char	*str);
char	**make_it_clear(int argc, char **argv);
void	pa(t_stack	**a, t_stack	**b);
void	pb(t_stack	**a, t_stack	**b);
void	sort_small(t_stack **a, t_stack **b, int size);
void	sort_large(t_stack **a, t_stack **b, int size);
void	reverse_rotate(t_stack	**stack);
void	rra(t_stack	**a);
void	rrb(t_stack	**b);
void	rrr(t_stack	**a, t_stack	**b);
void	rotate(t_stack	**stack);
void	ra(t_stack	**a);
void	rb(t_stack	**b);
void	rr(t_stack	**a, t_stack	**b);
void	sort_three_in_a(t_stack	**stack_a);
int		lenght(char *str);
int		is_sep(char c, char *charset);
int		count_word(char *str, char *charset);
char	*ft_strdup(char *start, int len);
char	**split_args(char *str, char charset);
int		stack_size(t_stack *stack_A);
void	swap(t_stack	**stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack	**a, t_stack	**b);
t_stack	*target(int min, int max, int value, t_stack *b);
t_stack	*be_or_not_to_be(t_stack *b, int value);
void	how_much_pain_for_this_number(t_stack **a, t_stack **b, t_stack *node);
int		get_total_cost(t_stack *node);
void	calc_costs(t_stack **a, t_stack **b, t_stack *node);
int		calculate_cost(int pos, int size);
int		find_position(t_stack *stack, int value);
int		find_min_position(t_stack *a, int *min_value);
void	push_the_laziest_number(t_stack **a, t_stack **b);
void	final_rotate(t_stack **a);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 20:59:45 by mikim             #+#    #+#             */
/*   Updated: 2017/08/19 22:51:24 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# define PS_COMP(a,b,c) (a < b && b < c)

typedef struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_inst
{
	char			*op;
	struct s_inst	*prev;
	struct s_inst	*next;
}					t_inst;

typedef struct		s_psflag
{
	int				visual;
	int				color;
	int				manual;
	int				next;
	int				res;
	int				file;
}					t_psflag;

typedef struct		s_psenv
{
	t_stack			*a;
	t_stack			*b;
	t_inst			*inst;
	t_psflag		flag;
	int				last;
	int				rr[3];
	int				rrr[3];
	int				crosa[2];
	int				crosb[2];
	int				len;
	int				fd;
}					t_psenv;

/*
**					checker
*/

void				checker(t_psenv *e);
void				check_stack(t_psenv *e);

/*
**					checker_inst
*/

void				run_chk_inst(t_psenv *e);
void				run_chk_next(t_psenv *e);
void				run_chk_manual(t_psenv *e);
void				check_op(t_psenv *e, char *inst);

/*
**					push_swap
*/

void				push_swap(t_psenv *e);
void				run_ps_auto(t_psenv *e);
void				run_ps_next(t_psenv *e);
void				run_ps_manual(t_psenv *e);
int					check_sorted(t_psenv *e);
void				check_sort_rot(t_psenv *e);
void				sort_rot(t_psenv *e, int cnt[2]);
t_stack				*get_last(t_stack *head);
void				get_operation(t_psenv *e);
void				write_inst(t_psenv *e);
void				store_push(t_psenv *e, char *op);
void				store_swap(t_psenv *e, char *op);
void				store_rotate(t_psenv *e, char *op);
void				store_reverse(t_psenv *e, char *op);

/*
**					my algo
*/

void				parse_stack(t_psenv *e);
int					parse_check(t_psenv *e);
int					check_push_swap(t_stack *a, t_stack *b);
int					check_rotate_a(t_psenv *e);
int					check_rotate_b(t_psenv *e);
int					check_rotate_r(t_psenv *e);
int					check_reverse_a(t_psenv *e);
int					check_reverse_b(t_psenv *e);
int					check_reverse_r(t_psenv *e);
int					check_cross_a(t_psenv *e);
int					check_cross_b(t_psenv *e);
void				get_push_swap(t_psenv *e);
void				get_rr_num(t_psenv *e, int cnt[2]);
void				get_rrr_num(t_psenv *e, int cnt[2], int max[2]);
void				get_corsa_num(t_psenv *e, int cnt[2], int max[2]);
void				get_crosb_num(t_psenv *e, int cnt[2], int max[2]);
void				get_stack_max(t_psenv *e, int max[2]);
void				get_op(t_psenv *e, int min[6]);
void				get_minimum(t_psenv *e, int tmp[2]);
void				get_minimum_rrrrr(t_psenv *e, int tmp[2]);

/*
**					rand_generator
*/

int					*ran_gen(int ran);
void				num_gen(int *arr, int ran, int *i);
int					check_dup(int *arr, int i, int gen);

/*
**					init_psenv
*/

int					init_psenv(t_psenv *e, char **av);
int					check_av(t_psenv *e, char *av);
void				add_stack(t_psenv *e, int n);
t_stack				*create_stack(int n);

/*
**					init_psflag
*/

void				init_psflag(t_psenv *e, char **av);
int					check_psflag(t_psenv *e, char c);
void				init_instfile(t_psenv *e, char **av, int i);

/*
**					init_inst
*/

void				init_inst(t_psenv *e);
t_inst				*create_inst(char *line);
void				add_inst(t_psenv *e, t_inst *n_inst);

/*
**					operator
*/

void				push_a(t_psenv *e);
void				push_b(t_psenv *e);
void				swap_a(t_psenv *e);
void				swap_b(t_psenv *e);
void				swap_s(t_psenv *e);
void				rotate_a(t_psenv *e);
void				rotate_b(t_psenv *e);
void				rotate_r(t_psenv *e);
void				reverse_a(t_psenv *e);
void				reverse_b(t_psenv *e);
void				reverse_r(t_psenv *e);

/*
**					print
*/

void				print_stack(t_psenv *e);
void				print_stack_color(t_psenv *e);
void				print_last(t_psenv *e);
void				print_last_color(t_psenv *e);
void				print_push(t_psenv *e, int colo);
void				print_push_stack(t_psenv *e, int colo);
void				print_push_color(t_psenv *e, t_stack *t1, t_stack *t2,
					int colo);
void				print_swap(t_psenv *e, int colo);
void				print_swap_stack(t_psenv *e, int colo);
void				print_swap_color(t_psenv *e, t_stack *t1, t_stack *t2,
					int colo);
void				print_rotate(t_psenv *e, int colo);
void				print_rotate_stack(t_psenv *e, int colo);
void				print_rotate_color(t_psenv *e, t_stack *t1, t_stack *t2,
					int colo);
void				print_reverse(t_psenv *e, int colo);
void				print_reverse_stack(t_psenv *e, int colo);
void				print_reverse_color(t_psenv *e, t_stack *t1, t_stack *t2,
					int colo);

/*
**					option
*/

void				read_opt(t_psenv *e, char *line);

/*
**					destroyer
*/

void				destroy_psenv(t_psenv *e);
void				destroy_stack(t_stack *head);
void				destroy_inst(t_inst *head);

/*
**					message
*/

void				ps_ok(t_psenv *e);
void				ps_ko(t_psenv *e);
void				ps_err(t_psenv *e);
void				ps_usage(int p);
void				ps_help(int p);

/*
** sa : swap a - swap the first 2 elem at the top of a
** sb : swap b - swap the first 2 elem at the top of b
** ss : sa & sb
** pa : push a - take the first elem at the top of b & put it at the top of a
** pb : push b - take the first elem at the top of a & put it at the top of b
** ra : rotate a - shift up all elem of a by 1. first >> last
** rb : rotate b - shift up all elem of b by 1. first >> last
** rr : ra & rb
** rra : reverse rotate a - shift down all elem of a by 1. last >> first
** rrb : reverse rotate b - shift down all elem of b by 1. last >> first
** rrr : rra & rrb
*/

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 14:55:55 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 15:49:47 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define PILE_A piles->pile_a
# define PILE_B piles->pile_b
# define SIZE_A piles->size_a
# define SIZE_B piles->size_b

# define P_A piles->pile_a
# define P_B piles->pile_b
# define S_A piles->size_a
# define S_B piles->size_b

# define NXT order->next

# define PALIER 30

typedef struct		s_order
{
	char			*s;
	struct s_order	*next;

}					t_order;

typedef struct		s_pile
{
	int				*pile_a;
	int				*pile_b;
	int				size_a;
	int				size_b;

}					t_pile;

/*
**	les fonctions liée au order du checker
*/
int					verif_order(t_order *order);
t_order				*get_order();

/*
** les fonctions liée au order de push_swap
*/
t_order				*find_order(int *pile_a, int *pile_b, int size);
void				put_order(t_order *order);
t_order				*new_order(char *s);
void				next_order(t_order	**begin, char *s);
t_order				*go_to_the_last_order(t_order *order);
t_order				*clean_unused_order(t_order *order);
t_order				*clean_null_order(t_order *order);
/*
** algorithme de resolution **
*/

/*
** first_algo
*/
t_order				*sort_other_int_order(t_pile *piles, int n, t_order **ord);
t_order				*sort_abc(int a, int b, int c, t_pile *piles);
t_order				*sorting_fusion(t_pile *piles);

int					mediane(int *tab, int size);
int					stay_number(int *pile, int size, int a, char c);

t_order				*go_back_to_a(t_pile *piles);
t_order				*go_back_to_b(t_pile *piles, int n);
t_order				*rotate_a(t_pile *piles, int n, char c);
/*
** second_algo
*/
t_order				*sorting_under_ten(t_pile *piles);
t_order				*home_sorting(int *pile, int size);
t_order				*sort_three_order(int a, int b, int c);
t_order				*sort_other_order(int **pile, int n, int *s, t_order **ord);

int					state_number(int nb, int *pile, int size, int i);
void				find_the_best_way(t_pile *piles, int *next, int *prev);

/*
** les fonctions liés au order disponible pour les 2 programmes
*/
void				free_order(t_order *order);

/*
** les fonction liée au parametres des 2 programmes
*/
int					*read_and_stock_params(int size, char **av);
int					verif_params(char **tab);
int					as_binome(int *tab, int size);
void				puttab_int(int *tab, int size);
int					is_sort(int	*tab, int size);

/*
** fonctions qui appliques un effet sur la pile disponible par les 2 programmes
*/
void				move_up(int **pile, int *size);
void				move_down(int **pile, int *size);

void				ft_sa_sb(int **pile_a, int size_a);
void				ft_ss(int **pile_a, int size_a, int **pile_b, int size_b);
void				ft_pa(int **pile_a, int *size_a, int **pile_b, int *size_b);
void				ft_pb(int **pile_a, int *size_a, int **pile_b, int *size_b);
void				ft_ra_rb(int **pile, int *size);
void				ft_rr(int **pile_a, int *size_a, int **pile_b, int *size_b);
void				ft_rra_rrb(int **pile, int *size);
void				ft_rrr(int **pile_a, int *siz_a, int **pile_b, int *siz_b);

/*
** les mains
*/
int					checker(int size, char **tab);
int					push_swap(int size, char **tab);
#endif

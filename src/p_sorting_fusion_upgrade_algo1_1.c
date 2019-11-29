/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_sorting_fusion_upgrade_algo1_1.c               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 19:55:12 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/28 14:55:15 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int			state_number(int nb, int *pile, int size, int i)
{
	int j;
	int k;

	j = 0;
	k = i;
	while (i < size)
	{
		if (pile[i] < nb)
			j++;
		i++;
	}
	i = k - 1;
	while (i >= 0)
	{
		if (pile[i] < nb)
			j++;
		i--;
	}
	return (j);
}

static void	execute_order_for_this_alog(t_order *ord, t_pile *piles)
{
	while (ord)
	{
		if (ord->s)
		{
			ft_strcmp(ord->s, "sa") == 0 ? ft_sa_sb(&P_A, S_A) : 0;
			ft_strcmp(ord->s, "sb") == 0 ? ft_sa_sb(&P_B, S_B) : 0;
			ft_strcmp(ord->s, "ss") == 0 ? ft_ss(&P_A, S_A, &P_B, S_B) : 0;
			ft_strcmp(ord->s, "pa") == 0 ? ft_pa(&P_A, &S_A, &P_B, &S_B) : 0;
			ft_strcmp(ord->s, "pb") == 0 ? ft_pb(&P_A, &S_A, &P_B, &S_B) : 0;
			ft_strcmp(ord->s, "ra") == 0 ? ft_ra_rb(&P_A, &S_A) : 0;
			ft_strcmp(ord->s, "rb") == 0 ? ft_ra_rb(&P_B, &S_B) : 0;
			ft_strcmp(ord->s, "rr") == 0 ? ft_rr(&P_A, &S_A, &P_B, &S_B) : 0;
			ft_strcmp(ord->s, "rra") == 0 ? ft_rra_rrb(&P_A, &S_A) : 0;
			ft_strcmp(ord->s, "rrb") == 0 ? ft_rra_rrb(&P_B, &S_B) : 0;
			ft_strcmp(ord->s, "rrr") == 0 ? ft_rrr(&P_A, &S_A, &P_B, &S_B) : 0;
		}
		ord = ord->next;
	}
}

t_order		*sorting_under_ten(t_pile *piles)
{
	t_order	*start;
	t_order	*order_end;
	t_order	*begin;
	int		n;

	if (!(start = new_order(NULL)))
		return (NULL);
	if (!(order_end = new_order(NULL)))
		return (NULL);
	begin = start;
	SIZE_B == 2 && P_B[0] < P_B[1] ? start->next = new_order("sb") : 0;
	SIZE_B == 2 && P_B[0] < P_B[1] ? ft_sa_sb(&P_B, SIZE_B) : 0;
	while (SIZE_B > 3)
	{
		n = state_number(*PILE_B, PILE_B, SIZE_B, 1);
		start->next = sort_other_int_order(piles, n, &order_end);
		start = start->next;
	}
	if (SIZE_B == 3 && !(start->next = sort_abc(P_B[0], P_B[1], P_B[2], piles)))
		return (NULL);
	while (start->next)
		start = start->next;
	start->next = order_end;
	execute_order_for_this_alog(order_end, piles);
	return (begin);
}

/*
** 1 = NEXT
** 0 = PREV
*/

void		find_the_best_way(t_pile *piles, int *next, int *prev)
{
	int i;
	int n;

	*next = 2147483647;
	*prev = 2147483647;
	i = 0;
	n = state_number(*PILE_B, PILE_B, SIZE_B, i);
	while (i < SIZE_B)
	{
		n = state_number(PILE_B[i], PILE_B, SIZE_B, i);
		if (n == 0 || n == SIZE_B - 2 || n == SIZE_B - 1)
		{
			i < *next ? *next = i : 0;
			SIZE_B - i < *prev ? *prev = SIZE_B - i : 0;
		}
		i++;
	}
}

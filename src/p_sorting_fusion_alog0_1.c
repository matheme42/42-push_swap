/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_sorting_fusion_alog0_1.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 18:58:59 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 03:21:45 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_order	*go_back_to_a(t_pile *piles)
{
	t_order *order;
	t_order *begin;

	order = new_order(NULL);
	begin = order;
	while (SIZE_B)
	{
		ft_pa(&PILE_A, &SIZE_A, &PILE_B, &SIZE_B);
		next_order(&order, "pa");
	}
	return (begin);
}

t_order	*go_back_to_b(t_pile *piles, int n)
{
	t_order *order;
	t_order *begin;

	order = new_order(NULL);
	begin = order;
	while (n--)
	{
		ft_pb(&PILE_A, &SIZE_A, &PILE_B, &SIZE_B);
		next_order(&order, "pb");
	}
	return (begin);
}

int		stay_number(int *pile, int size, int a, char c)
{
	int i;

	i = 0;
	while (i < size && c == 'D')
	{
		if (pile[i] < a)
			return (1);
		i++;
	}
	while (i < size && c == 'U')
	{
		if (pile[i] >= a)
			return (1);
		i++;
	}
	return (0);
}

t_order	*rotate_a(t_pile *piles, int n, char c)
{
	t_order *order;
	t_order *begin;

	order = new_order(NULL);
	begin = order;
	while (c == 'U' && n > 0)
	{
		ft_ra_rb(&PILE_A, &SIZE_A);
		next_order(&order, "ra");
		n--;
	}
	while (c == 'D' && n > 0)
	{
		ft_rra_rrb(&PILE_A, &SIZE_A);
		next_order(&order, "rra");
		n--;
	}
	return (begin);
}

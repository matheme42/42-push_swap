/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_sorting_fusion_algo0_0.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 14:40:38 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 19:10:51 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static t_order	*rotate_split_medianne_a(t_pile *piles, int s)
{
	int		i;
	int		m;
	t_order *order;
	t_order *begin;

	i = 0;
	m = mediane(PILE_A, SIZE_A - s);
	order = new_order(NULL);
	begin = order;
	while (i < SIZE_A - s && stay_number(PILE_A, SIZE_A - i - s, m, 'D'))
	{
		while (*PILE_A < m)
		{
			next_order(&order, "pb");
			ft_pb(&PILE_A, &SIZE_A, &PILE_B, &SIZE_B);
		}
		if (SIZE_A - s - SIZE_B > 1)
		{
			next_order(&order, "ra");
			ft_ra_rb(&PILE_A, &SIZE_A);
		}
		i++;
	}
	return (begin);
}

static t_order	*rotate_split_medianne_b(t_pile *piles, int s)
{
	int		i;
	int		m;
	t_order *order;
	t_order *begin;

	i = 0;
	m = mediane(PILE_B, s);
	order = new_order(NULL);
	begin = order;
	while (i < SIZE_B && stay_number(PILE_B, s - i, m, 'U'))
	{
		while (PILE_B[0] >= m)
		{
			next_order(&order, "pa");
			ft_pa(&PILE_A, &SIZE_A, &PILE_B, &SIZE_B);
		}
		next_order(&order, "rb");
		ft_ra_rb(&PILE_B, &SIZE_B);
		i++;
	}
	return (begin);
}

static t_order	*split_medianne_b(t_pile *piles)
{
	t_order *order;
	t_order *begin;
	int		n;

	order = new_order(NULL);
	begin = order;
	n = SIZE_B;
	if (SIZE_B > PALIER)
	{
		order->next = rotate_split_medianne_b(piles, SIZE_B);
		order = go_to_the_last_order(order);
		order->next = split_medianne_b(piles);
		order = go_to_the_last_order(order);
		order->next = go_back_to_b(piles, n - n / 2);
		order = go_to_the_last_order(order);
		order->next = split_medianne_b(piles);
		return (begin);
	}
	order->next = sorting_under_ten(piles);
	order = go_to_the_last_order(order);
	order->next = go_back_to_a(piles);
	order = go_to_the_last_order(order);
	order->next = rotate_a(piles, n, 'U');
	return (begin);
}

t_order			*sorting_fusion(t_pile *piles)
{
	t_order	*order;
	t_order	*begin;

	order = new_order(NULL);
	begin = order;
	order->next = rotate_split_medianne_a(piles, 0);
	order = go_to_the_last_order(order);
	order->next = split_medianne_b(piles);
	order = go_to_the_last_order(order);
	order->next = go_back_to_b(piles, SIZE_A - SIZE_A / 2);
	order = go_to_the_last_order(order);
	order->next = split_medianne_b(piles);
	return (begin);
}

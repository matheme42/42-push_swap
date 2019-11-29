/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_sorting_fusion_upgrade_algo1_2.c               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 19:55:12 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/28 14:56:04 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static t_order	*n_equal_zero(t_order **order_end, t_pile *piles)
{
	t_order *order;
	t_order *end;

	if (!(order = new_order("pa")))
		return (NULL);
	ft_pa(&PILE_A, &SIZE_A, &PILE_B, &SIZE_B);
	order->next = NULL;
	if (!(end = new_order("pb")))
		return (NULL);
	end->next = *order_end;
	*order_end = end;
	return (order);
}

static t_order	*n_equal_last_one(t_order **order_end, t_pile *piles)
{
	t_order *order;
	t_order *end;

	if (!(order = new_order("pa")))
		return (NULL);
	ft_pa(&PILE_A, &SIZE_A, &PILE_B, &SIZE_B);
	order->next = NULL;
	if (!(end = new_order("pb")))
		return (NULL);
	if (!(end->next = new_order("sb")))
		return (NULL);
	end->next->next = *order_end;
	*order_end = end;
	return (order);
}

static t_order	*n_equal_all(t_order **order_end, t_pile *piles)
{
	t_order *order;
	t_order *end;

	if (!(order = new_order("pa")))
		return (NULL);
	ft_pa(&PILE_A, &SIZE_A, &PILE_B, &SIZE_B);
	order->next = NULL;
	if (!(end = new_order("pb")))
		return (NULL);
	if (!(end->next = new_order("rb")))
		return (NULL);
	end->next->next = *order_end;
	*order_end = end;
	return (order);
}

/*
** find_the_best_way
** 1 = NEXT (ra)
** 0 = PREV (rra)
*/

static t_order	*n_equal_other(t_pile *piles)
{
	t_order *order;
	int		next;
	int		prev;

	find_the_best_way(piles, &next, &prev);
	if (next < prev)
	{
		if (!(order = new_order("rb")))
			return (NULL);
		ft_ra_rb(&PILE_B, &SIZE_B);
	}
	else
	{
		if (!(order = new_order("rrb")))
			return (NULL);
		ft_rra_rrb(&PILE_B, &SIZE_B);
	}
	return (order);
}

t_order			*sort_other_int_order(t_pile *piles, int n, t_order **order_end)
{
	if (n == 0)
		return (n_equal_all(order_end, piles));
	else if (n == SIZE_B - 2)
		return (n_equal_last_one(order_end, piles));
	else if (n == SIZE_B - 1)
		return (n_equal_zero(order_end, piles));
	else
		return (n_equal_other(piles));
	return (new_order(NULL));
}

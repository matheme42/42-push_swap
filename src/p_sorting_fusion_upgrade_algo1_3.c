/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_sorting_fusion_upgrade_algo1_3.c               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 14:34:26 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/28 12:21:23 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static t_order	*sort_three_int(int a, int c, t_pile *piles)
{
	t_order *order;

	if (!(order = new_order("rrb")))
		return (NULL);
	ft_rra_rrb(&PILE_B, &SIZE_B);
	if (a > c)
	{
		if (!(order->next = new_order("sb")))
		{
			free(order);
			return (NULL);
		}
		ft_sa_sb(&PILE_B, SIZE_B);
	}
	return (order);
}

static t_order	*sort_three_int2(int a, int c, t_pile *piles)
{
	t_order *order;

	if (a > c)
	{
		if (!(order = new_order("sb")))
			return (NULL);
		ft_sa_sb(&PILE_B, SIZE_B);
	}
	else
	{
		if (!(order = new_order("rb")))
			return (NULL);
		ft_ra_rb(&PILE_B, &SIZE_B);
	}
	return (order);
}

static t_order	*sort_three_int3(t_pile *piles)
{
	t_order *order;

	if (!(order = new_order("rb")))
		return (NULL);
	ft_ra_rb(&PILE_B, &SIZE_B);
	if (!(order->next = new_order("sb")))
	{
		free(order);
		return (NULL);
	}
	ft_sa_sb(&PILE_B, SIZE_B);
	return (order);
}

t_order			*sort_abc(int a, int b, int c, t_pile *piles)
{
	if (a < b && b < c)
		return (sort_three_int3(piles));
	if (a < b && b > c)
		return (sort_three_int2(a, c, piles));
	if (a > b && b < c)
		return (sort_three_int(a, c, piles));
	else if (a > b && b > c)
		return (new_order(NULL));
	return (NULL);
}

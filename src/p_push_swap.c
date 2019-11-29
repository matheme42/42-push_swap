/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_push_swap.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 11:06:31 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/05 16:38:30 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static int	error(int error)
{
	if (error == -1)
		ft_putstr("Error\n");
	return (1);
}

static int	init_pile(int size, char **tab, t_pile *piles)
{
	PILE_A = NULL;
	PILE_B = NULL;
	SIZE_A = size;
	SIZE_B = 0;
	if (verif_params(tab))
		return (error(-1));
	if (!(PILE_A = read_and_stock_params(size, tab)))
		return (error(-1));
	if (!(PILE_B = (int*)malloc(sizeof(int) * (size + 1))))
		return (error(-1));
	if (as_binome(PILE_A, size))
		return (error(-1));
	if (!is_sort(PILE_A, size))
		return (error(0));
	return (0);
}

int			push_swap(int size, char **tab)
{
	t_pile	piles;
	t_order *order;

	if (init_pile(size, tab, &piles))
	{
		free(piles.pile_a);
		free(piles.pile_b);
		return (1);
	}
	if (size == 2)
	{
		piles.pile_a[0] > piles.pile_a[1] ? ft_putstr("sa\n") : 0;
		return (0);
	}
	if (size > 70)
		order = sorting_fusion(&piles);
	else
		order = home_sorting(piles.pile_a, piles.size_a);
	order = clean_unused_order(order);
	put_order(order);
	free_order(order);
	free(piles.pile_a);
	free(piles.pile_b);
	return (0);
}

int			main(int ac, char **av)
{
	if (ac >= 2)
		push_swap(ac - 1, &av[1]);
	return (0);
}

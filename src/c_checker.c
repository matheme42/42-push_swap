/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c_checker.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 13:39:45 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 19:10:57 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	error(int *pile_a, int *pile_b, t_order *order, int i)
{
	pile_a ? free(pile_a) : 0;
	pile_b ? free(pile_b) : 0;
	order ? free_order(order) : 0;
	i == -1 ? ft_putstr("Error\n") : 0;
	return (i);
}

int	sort_or_shuffle(int *pile_a, int size)
{
	int i;
	int c;

	if (size <= 1)
	{
		free(pile_a);
		return (0);
	}
	i = 1;
	c = pile_a[0];
	while (i < size)
	{
		if (pile_a[i] < c)
		{
			free(pile_a);
			return (1);
		}
		c = pile_a[i];
		i++;
	}
	free(pile_a);
	return (0);
}

int	execute_order(int **p_a, int **p_b, t_order *ord, int size)
{
	int size_a;
	int size_b;

	size_a = size;
	size_b = 0;
	while (ord->next)
	{
		ft_strcmp(ord->s, "sa") == 0 ? ft_sa_sb(p_a, size_a) : 0;
		ft_strcmp(ord->s, "sb") == 0 ? ft_sa_sb(p_b, size_b) : 0;
		ft_strcmp(ord->s, "ss") == 0 ? ft_ss(p_a, size_a, p_b, size_b) : 0;
		ft_strcmp(ord->s, "pa") == 0 ? ft_pa(p_a, &size_a, p_b, &size_b) : 0;
		ft_strcmp(ord->s, "pb") == 0 ? ft_pb(p_a, &size_a, p_b, &size_b) : 0;
		ft_strcmp(ord->s, "ra") == 0 ? ft_ra_rb(p_a, &size_a) : 0;
		ft_strcmp(ord->s, "rb") == 0 ? ft_ra_rb(p_b, &size_b) : 0;
		ft_strcmp(ord->s, "rr") == 0 ? ft_rr(p_a, &size_a, p_b, &size_b) : 0;
		ft_strcmp(ord->s, "rra") == 0 ? ft_rra_rrb(p_a, &size_a) : 0;
		ft_strcmp(ord->s, "rrb") == 0 ? ft_rra_rrb(p_b, &size_b) : 0;
		ft_strcmp(ord->s, "rrr") == 0 ? ft_rrr(p_a, &size_a, p_b, &size_b) : 0;
		ord = ord->next;
	}
	return (size_b);
}

int	checker(int size, char **tab)
{
	int		*pile_a;
	int		*pile_b;
	t_order *order;

	pile_a = NULL;
	pile_b = NULL;
	order = NULL;
	if (verif_params(tab))
		return (error(NULL, NULL, NULL, -1));
	if (!(pile_a = read_and_stock_params(size, tab)))
		return (error(NULL, NULL, NULL, -1));
	if (as_binome(pile_a, size))
		return (error(pile_a, NULL, NULL, -1));
	if (!(pile_b = (int*)malloc(sizeof(int) * (size + 1))))
		return (error(pile_a, NULL, NULL, -1));
	if (!(order = get_order()))
		return (error(pile_a, pile_b, order, -1));
	if (verif_order(order))
		return (error(pile_a, pile_b, order, -1));
	if (execute_order(&pile_a, &pile_b, order, size))
		return (error(pile_a, pile_b, order, 1));
	free(pile_b);
	free_order(order);
	return (sort_or_shuffle(pile_a, size));
}

int	main(int ac, char **av)
{
	int retn;

	if (ac >= 2)
	{
		retn = checker(ac - 1, &av[1]);
		if (retn > 0)
			ft_putstr("KO\n");
		else if (retn == 0)
			ft_putstr("OK\n");
	}
	return (0);
}

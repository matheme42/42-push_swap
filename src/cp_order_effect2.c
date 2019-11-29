/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cp_order_effect2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 20:17:59 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/19 14:36:49 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(int **pile, int size)
{
	int c;

	if (size < 2)
		return ;
	c = (*pile)[0];
	(*pile)[0] = (*pile)[1];
	(*pile)[1] = c;
}

void	ft_ss(int **pile_a, int size_a, int **pile_b, int size_b)
{
	ft_sa_sb(pile_a, size_a);
	ft_sa_sb(pile_b, size_b);
}

void	ft_pa(int **pile_a, int *size_a, int **pile_b, int *size_b)
{
	if (*size_b < 1)
		return ;
	move_up(pile_a, size_a);
	(*pile_a)[0] = (*pile_b)[0];
	move_down(pile_b, size_b);
}

void	ft_pb(int **pile_a, int *size_a, int **pile_b, int *size_b)
{
	if (*size_a < 1)
		return ;
	move_up(pile_b, size_b);
	(*pile_b)[0] = (*pile_a)[0];
	move_down(pile_a, size_a);
}

void	ft_ra_rb(int **pile, int *size)
{
	int b;

	if (*size == 1)
		return ;
	b = (*pile)[0];
	move_down(pile, size);
	(*pile)[*size] = b;
	(*size)++;
}

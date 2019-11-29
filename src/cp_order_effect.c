/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cp_order_effect.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 19:14:05 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/19 14:36:44 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	move_up(int **pile, int *size)
{
	int i;
	int b;
	int tmp;

	i = 1;
	if (*size < 1)
	{
		(*size)++;
		return ;
	}
	b = (*pile)[0];
	while (i <= *size)
	{
		tmp = (*pile)[i];
		(*pile)[i] = b;
		i++;
		b = tmp;
	}
	(*size)++;
}

void	move_down(int **pile, int *size)
{
	int i;
	int b;
	int tmp;

	i = *size - 1;
	if (*size < 1)
		return ;
	b = (*pile)[0];
	while (i >= 0)
	{
		tmp = (*pile)[i];
		(*pile)[i] = b;
		b = tmp;
		i--;
	}
	(*size)--;
}

void	ft_rra_rrb(int **pile, int *size)
{
	if (*size == 1)
		return ;
	move_up(pile, size);
	(*pile)[0] = (*pile)[*size - 1];
	(*size)--;
}

void	ft_rr(int **pile_a, int *size_a, int **pile_b, int *size_b)
{
	ft_ra_rb(pile_a, size_a);
	ft_ra_rb(pile_b, size_b);
}

void	ft_rrr(int **pile_a, int *size_a, int **pile_b, int *size_b)
{
	ft_rra_rrb(pile_a, size_a);
	ft_rra_rrb(pile_b, size_b);
}

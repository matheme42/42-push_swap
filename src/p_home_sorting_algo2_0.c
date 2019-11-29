/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_home_sorting_algo2_0.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 18:31:27 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 18:48:43 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_order	*home_sorting(int *pile, int size)
{
	t_order	*order_begin;
	t_order	*order_end;
	t_order	*begin;
	int		n;

	if (!(order_begin = new_order(NULL)))
		return (NULL);
	if (!(order_end = new_order(NULL)))
		return (NULL);
	begin = order_begin;
	while (size > 3)
	{
		n = state_number(pile[0], pile, size, 1);
		order_begin->next = sort_other_order(&pile, n, &size, &order_end);
		n == 0 || n == 1 || n == size - 1 ? move_down(&pile, &size) : 0;
		order_begin = order_begin->next;
	}
	if (!(order_begin->next = sort_three_order(pile[0], pile[1], pile[2])))
		return (NULL);
	while (order_begin->next)
		order_begin = order_begin->next;
	order_begin->next = order_end;
	return (begin);
}

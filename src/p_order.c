/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_order.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 15:40:58 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 00:59:12 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

/*
** libere la liste chainés
*/

void	put_order(t_order *order)
{
	while (order)
	{
		if (order->s)
		{
			ft_putstr(order->s);
			ft_putchar('\n');
		}
		order = order->next;
	}
}

void	free_order(t_order *order)
{
	t_order *tmp;

	while (order)
	{
		tmp = order->next;
		if (order->s)
			free(order->s);
		free(order);
		order = tmp;
	}
}

t_order	*clean_unused_order(t_order *order)
{
	t_order *begin;
	t_order *tmp;

	order = clean_null_order(order);
	begin = order;
	while (order->next && order->next->next)
	{
		if (order->next->s && order->next->next->s)
		{
			tmp = NULL;
			if ((!ft_strcmp(NXT->s, "pb") && !ft_strcmp(NXT->next->s, "pa"))
			|| (!ft_strcmp(NXT->s, "ra") && !ft_strcmp(NXT->next->s, "rra")))
			{
				tmp = order->next->next->next;
				free(order->next->next->s);
				free(order->next->next);
				free(order->next->s);
				free(order->next);
				order->next = tmp;
				order = begin;
			}
			tmp == NULL ? order = order->next : 0;
		}
	}
	return (begin);
}

t_order	*clean_null_order(t_order *order)
{
	t_order *begin;
	t_order *tmp;

	begin = order;
	while (order->next)
	{
		if (order->next->s == NULL)
		{
			tmp = order->next->next;
			free(order->next);
			order->next = tmp;
		}
		else
			order = order->next;
	}
	return (begin);
}

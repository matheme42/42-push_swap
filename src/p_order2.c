/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_order2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 18:43:54 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/28 18:47:34 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_order	*new_order(char *s)
{
	t_order	*order;

	if (!(order = malloc(sizeof(t_order))))
		return (NULL);
	if (!s)
		order->s = NULL;
	else if (!(order->s = ft_strdup(s)))
	{
		free(order);
		return (NULL);
	}
	order->next = NULL;
	return (order);
}

void	next_order(t_order **begin, char *s)
{
	t_order *next;

	next = new_order(s);
	(*begin)->next = next;
	(*begin) = (*begin)->next;
}

t_order	*go_to_the_last_order(t_order *order)
{
	while (order->next)
		order = order->next;
	return (order);
}

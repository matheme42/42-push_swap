/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_home_sorting_algo2_1.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/22 18:34:57 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 18:48:41 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static t_order	*free_error(t_order *order, t_order *norder, char *str)
{
	if (norder)
		free(norder);
	if (str)
		free(str);
	if (order)
		free(order);
	return (NULL);
}

static t_order	*sort_three_int(int a, int c)
{
	t_order *order;

	if (!(order = malloc(sizeof(t_order))))
		return (NULL);
	if (!(order->s = ft_strdup("rra")))
		return (free_error(order, NULL, NULL));
	order->next = NULL;
	if (a < c)
	{
		if (!(order->next = malloc(sizeof(t_order))))
			return (free_error(order, NULL, order->s));
		if (!(order->next->s = ft_strdup("sa")))
			return (free_error(order, order->next, order->s));
		order->next->next = NULL;
	}
	return (order);
}

static t_order	*sort_three_int2(int a, int c)
{
	t_order *order;

	if (!(order = malloc(sizeof(t_order))))
		return (NULL);
	if (a < c)
	{
		if (!(order->s = ft_strdup("sa")))
			return (free_error(order, NULL, NULL));
	}
	else
	{
		if (!(order->s = ft_strdup("ra")))
			return (free_error(order, NULL, NULL));
	}
	order->next = NULL;
	return (order);
}

static t_order	*sort_three_int3(void)
{
	t_order *order;

	if (!(order = malloc(sizeof(t_order))))
		return (NULL);
	if (!(order->s = ft_strdup("ra")))
		return (free_error(order, NULL, NULL));
	if (!(order->next = malloc(sizeof(t_order))))
		return (free_error(order, NULL, order->s));
	if (!(order->next->s = ft_strdup("sa")))
		return (free_error(order, order->next, order->s));
	order->next->next = NULL;
	return (order);
}

t_order			*sort_three_order(int a, int b, int c)
{
	t_order *order;

	if (a < b && b < c)
	{
		if (!(order = malloc(sizeof(t_order))))
			return (NULL);
		order->s = NULL;
		order->next = NULL;
		return (order);
	}
	else if (a < b && b > c)
		return (sort_three_int(a, c));
	else if (a > b && b < c)
		return (sort_three_int2(a, c));
	else if (a > b && b > c)
		return (sort_three_int3());
	return (NULL);
}

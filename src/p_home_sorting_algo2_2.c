/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_home_sorting_algo2_2.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 18:26:24 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 19:18:47 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static t_order	*n_equal_zero(t_order **order_end)
{
	t_order *order;
	t_order *end;

	if (!(order = malloc(sizeof(t_order))))
		return (NULL);
	order->s = ft_strdup("pb");
	order->next = NULL;
	if (!(end = malloc(sizeof(t_order))))
		return (NULL);
	end->s = ft_strdup("pa");
	end->next = *order_end;
	*order_end = end;
	return (order);
}

static t_order	*n_equal_one(t_order **order_end)
{
	t_order *order;
	t_order *end;

	if (!(order = malloc(sizeof(t_order))))
		return (NULL);
	order->s = ft_strdup("pb");
	order->next = NULL;
	if (!(end = malloc(sizeof(t_order))))
		return (NULL);
	end->s = ft_strdup("pa");
	end->next = malloc(sizeof(t_order));
	end->next->s = ft_strdup("sa");
	end->next->next = *order_end;
	*order_end = end;
	return (order);
}

static t_order	*n_equal_all(t_order **order_end)
{
	t_order *order;
	t_order *end;

	if (!(order = malloc(sizeof(t_order))))
		return (NULL);
	order->s = ft_strdup("pb");
	order->next = NULL;
	if (!(end = malloc(sizeof(t_order))))
		return (NULL);
	end->s = ft_strdup("pa");
	end->next = malloc(sizeof(t_order));
	end->next->s = ft_strdup("ra");
	end->next->next = *order_end;
	*order_end = end;
	return (order);
}

static t_order	*n_equal_other(int **pile, int *size)
{
	t_order *order;

	if (!(order = new_order("ra")))
		return (NULL);
	ft_ra_rb(pile, size);
	return (order);
}

t_order			*sort_other_order(int **pile, int n, int *size, t_order **end)
{
	if (n == 0)
		return (n_equal_zero(end));
	else if (n == 1)
		return (n_equal_one(end));
	else if (n == *size - 1)
		return (n_equal_all(end));
	else
		return (n_equal_other(pile, size));
	return (NULL);
}

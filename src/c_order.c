/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c_order.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 18:01:29 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 18:44:28 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

/*
** libere la liste chainés
*/

void		free_order(t_order *order)
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

/*
** récupére les ordres à effectuer
*/

t_order		*get_order(void)
{
	t_order *order;
	t_order	*begin;
	char	*tmp;

	if (!(order = malloc(sizeof(t_order))))
		return (NULL);
	begin = order;
	while (get_next_line(0, &tmp))
	{
		order->s = ft_strsub(tmp, 0, ft_strlen(tmp));
		free(tmp);
		if (!(order->next = malloc(sizeof(t_order))))
			return (NULL);
		order = order->next;
	}
	if (!(order->s = ft_strnew(0)))
		return (0);
	order->next = NULL;
	return (begin);
}

/*
** initialise une whitelist des commandes accepter
*/

static char	**init_order_model(void)
{
	char	**m;
	int		i;

	if (!(m = malloc(sizeof(char*) * 12)))
		return (NULL);
	m[0] = ft_strdup("sa");
	m[1] = ft_strdup("sb");
	m[2] = ft_strdup("ss");
	m[3] = ft_strdup("pa");
	m[4] = ft_strdup("pb");
	m[5] = ft_strdup("ra");
	m[6] = ft_strdup("rb");
	m[7] = ft_strdup("rr");
	m[8] = ft_strdup("rra");
	m[9] = ft_strdup("rrb");
	m[10] = ft_strdup("rrr");
	m[11] = NULL;
	i = -1;
	while (++i <= 10)
		if (m[i] == NULL)
			return (NULL);
	return (m);
}

/*
** libere la whitelist des commandes accepter
*/

static void	clean_order_model(char **model)
{
	int	i;

	i = -1;
	while (++i <= 10)
		free(model[i]);
	free(model);
}

/*
** verifie que les commande passé en parametre sont contenu dans la whitelist
*/

int			verif_order(t_order *order)
{
	char	**order_model;
	int		i;

	if (!order)
		return (1);
	if (!(order_model = init_order_model()))
		return (1);
	while (order->next)
	{
		i = -1;
		while (order_model[++i])
			if (!ft_strcmp(order->s, order_model[i]))
				break ;
		if (!order_model[i])
		{
			clean_order_model(order_model);
			return (1);
		}
		order = order->next;
	}
	clean_order_model(order_model);
	return (0);
}

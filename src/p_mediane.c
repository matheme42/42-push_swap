/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   p_mediane.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 15:28:39 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/25 16:55:51 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static int	min(int *tab, int size)
{
	int i;
	int n;

	i = -1;
	n = 2147483647;
	while (++i < size)
		tab[i] < n ? n = tab[i] : 0;
	return (n);
}

static int	minupper(int *tab, int size, int z)
{
	int i;
	int n;

	i = -1;
	n = 2147483647;
	while (++i < size)
		tab[i] < n && tab[i] > z ? n = tab[i] : 0;
	return (n);
}

int			mediane(int *tab, int size)
{
	int id;
	int n;

	id = -1;
	n = min(tab, size);
	while (++id < size / 2)
		n = minupper(tab, size, n);
	return (n);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cp_params.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 18:36:52 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/22 18:45:44 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

/*
** cette fonction permet de prendre un double tableau de char et
** de le transformer en double tableau d'int
** cette fonction verifie également que le chiffre obtenu est contenu
** dans un int
*/

int		*read_and_stock_params(int size, char **av)
{
	int		*tab;
	long	nb;
	int		i;

	if (!(tab = (int*)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		nb = ft_atol(av[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			free(tab);
			return (NULL);
		}
		tab[i] = (int)nb;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

/*
** cette fonction permet de verifier que les arguments passé en
** parametre sont bien digitale
*/

int		verif_params(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][0] == '-')
			j++;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
** cette fonction permet de verfier la qu'il n'y a pas
** la présence de binome dans les parametres donnés
*/

int		as_binome(int *tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i] == tab[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
** permet d'afficher les parametres donnés
*/

void	puttab_int(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int		is_sort(int *tab, int size)
{
	int i;
	int retn;

	i = 0;
	retn = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
			retn = 1;
		i++;
	}
	return (retn);
}

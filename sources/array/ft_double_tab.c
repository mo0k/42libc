/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:45:53 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/20 20:46:35 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

void			ft_print_double_tab(char **tab)
{
	if (!tab)
		return ;
	while (*tab)
	{
		write(1, *tab, ft_strlen(*tab));
		++tab;
	}
}

char 			**ft_get_double_tab(int height, int width)
{
	char	**tab;
	int		i;

	i = -1;
	if (!(tab = (char**)malloc(sizeof(char*) * (height + 1))))
		return (NULL);
	tab[height] = NULL;
	while (++i < height)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * (width + 1))))
		{
			ft_delete_double_tab(tab);
			return (NULL);
		}
		tab[i][width] = 0;
	}
	return (tab);
}

void	ft_delete_double_tab(char **tab)
{
	//dprintf(2, "start delete double tab\n");
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		//dprintf(2, "\ttab[%d](%p):%s\n", i, tab[i], tab[i]);
		free(tab[i]);
		i++;
	}
	//dprintf(2, "\ttab[%d](%p)\n", i, tab[i]);
	free(tab);
	tab = NULL;
	//ft_memdel((void*)tab);
	//dprintf(2, "fin delete double tab\n");
}

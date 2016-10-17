/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strenqu.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/16/10 12:51:02 by jmoucade          #+#    #+#             */
/*   Updated: 2016/17/10 12:25:30 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1,char const *s2, size_t n)
{
	
	if (s1 && s2)
	{
		if(ft_strncmp(s1, s2, n) != 0)
			return (0);
		else
			return (1);
	}
	return (0);
}

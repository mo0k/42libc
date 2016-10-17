/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/16/10 12:51:02 by jmoucade          #+#    #+#             */
/*   Updated: 2016/17/10 12:25:30 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int i;
	char *str;

	str = NULL;
	i = -1;
	if (s && f)
	{
		if ((str = ft_strnew(ft_strlen(s))))
		{
			while (s[++i])
				str[i] = f(s[i]);
		}
	}
	return (str);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 07:01:02 by jmoucade          #+#    #+#             */
/*   Updated: 2016/08/15 16:16:31 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		len_to_find;
	int		i;
	int		j;

	i = 0;
	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return ((char *)str);
	while (i < (int)len)
	{
		j = 0;
		while (i + j != (int)len && str[i + j] == to_find[j] && str[i + j])
		{
			if (j == len_to_find - 1)
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

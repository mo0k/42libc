/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 07:01:02 by jmoucade          #+#    #+#             */
/*   Updated: 2016/08/15 16:16:31 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int len;
	int i;
	int j;

	i = -1;
	len = ft_strlen(to_find);
	while (str[++i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j])
		{
			if (j == len - 1)
				return ((char *)str + i);
			j++;
		}
	}
	return ((char *)str);
}

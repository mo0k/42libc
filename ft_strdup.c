/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 05:58:13 by jmoucade          #+#    #+#             */
/*   Updated: 2016/10/10 22:58:15 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strdup(const char *src)
{
	int		ct;
	char	*ptr;

	ct = 0;
	ptr = NULL;
	if (!(ptr = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
			return (NULL);
		while (src[ct])
		{
			ptr[ct] = src[ct];
			ct++;
		}
		ptr[ct] = '\0';
	return (ptr);
}

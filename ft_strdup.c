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

char		*ft_strdup(char *src)
{
	int		ct;
	char	*ptr;

	ct = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (0);
	while (src[ct])
	{
		ptr[ct] = src[ct];
		ct++;
	}
	ptr[ct] = '\0';
	return (ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:36:34 by jmoucade          #+#    #+#             */
/*   Updated: 2017/09/09 16:04:36 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
		char		*ptr;

	if (!s)
		return (NULL);
	//len = ft_strlen(s) + 1;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			return ((char *)s + (ptr - s));
		++ptr;
	}
	return (NULL);
}

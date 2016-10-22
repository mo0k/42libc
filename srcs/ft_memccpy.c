/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/13/10 22:52:04 by jmoucade          #+#    #+#             */
/*   Updated: 2016/14/10 12:23:35 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr_dst;
	char	*ptr_src;
	size_t	i;

	i = 0;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	while (i < n)
	{
		if (ptr_src[i] == c)
			return (dst + i + 1);
		else
			ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (NULL);
}

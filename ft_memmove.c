/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/13/10 22:52:04 by jmoucade          #+#    #+#             */
/*   Updated: 2016/14/10 12:23:35 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_dst;
	char	*str_src;
	char	tmp[len];
	size_t	i;

	i = 0;
	str_dst = (char *)dst;
	str_src = (char *)src;
	ft_memset(tmp, 0, len);
	ft_memcpy(tmp, str_src, len);
	ft_memcpy(dst, tmp, len);
	return (dst);
}

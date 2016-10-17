/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 03:50:51 by jmoucade          #+#    #+#             */
/*   Updated: 2016/08/20 02:45:15 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	len;
	unsigned int	len_src;

	len_src = ft_strlen(src);
	len = 0;
	while (src[len] && len < n)
	{
		dest[len] = src[len];
		len++;
	}
	if (n > len_src)
		dest[len] = '\0';
	return (dest);
}

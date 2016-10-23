/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:19:06 by jmoucade          #+#    #+#             */
/*   Updated: 2016/08/15 17:45:44 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*		ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ptr;
	
	ptr = NULL;
	if (s)
	{
		if ((ptr = ft_strnew(len)))
			ptr = ft_strncpy(ptr, s + start, len);
	}
	return (ptr);
}
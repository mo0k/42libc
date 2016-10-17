/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:19:06 by jmoucade          #+#    #+#             */
/*   Updated: 2016/08/15 17:45:44 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;
	
	ptr = NULL;
	if (s1 && s2)
	{
		if ((ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			ptr = ft_strcpy(ptr, s1);
			ptr = ft_strcat(ptr, s2);
		}
	}
	return (ptr);
}
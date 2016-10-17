/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/16/10 12:52:04 by jmoucade          #+#    #+#             */
/*   Updated: 2016/17/10 12:23:35 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char *ptr;

	if (!size || !(ptr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(ptr, size + 1);
	return (ptr);
}
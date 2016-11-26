/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:37:29 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:37:31 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	int len;

	len = -1;
	while (*(src + ++len))
		*(dest + len) = *(src + len);
	*(dest + len) = '\0';
	return (dest);
}
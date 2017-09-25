/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 23:30:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/21 00:33:15 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchars.h>

char	ft_wcharlen(wchar_t c)
{
	/*
	unsigned int e;

	e = (unsigned int)c;
	if (c >= 0 && c <= 127)
		return (1);
	else if (e > 127 && e < 0x10FFFF)
	{
		if (e < 0x07FF)
			return (2);
		else if (e < 0xFFFF)
			return (3);
		else
			return (4);
	}
	else
		return (0);
	*/
	if (MB_CUR_MAX == 1)
	{
		//printf("par ici\n");
		if (c >= 0 && c <= 0xFF)
		{
			return (1);
		}
		return (0);
	}
	else if (c >= 0 && c < 0x10FFFF)
	{
		//printf("par la\n");
		if (c >= 0 && c <= 0x7F)
			return (1);
		else if (c >= 0x80 && c <= 0x7FF)
			return (2);
		else if ((c >= 0x800 && c <= 0xD7FF) || (c >= 0xE000 && c <= 0xFFFF))
			return (3);
		else if (c >= 0x10000 && c <= 0x10FFFF)
			return (4);
		else
			return (0);
		//return (1);
		//printf("result:%s\n", c);
	}
	else
	{
		//printf("ha non par la\n");
		return (0);
	}
}

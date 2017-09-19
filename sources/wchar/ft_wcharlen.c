/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 23:30:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/15 23:52:45 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchars.h>

char	ft_wcharlen(wchar_t c)
{
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
}

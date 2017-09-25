/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:55:24 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/24 20:55:45 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchars.h>

int		ft_wstrnlen(wchar_t *str, int n)
{
	int	wstrlen;
	int wcharlen;

	wstrlen = 0;
	if (n <= 0)
		return (0);
	while (*str)
	{
		if (!(wcharlen = ft_wcharlen(*str)))
		{
			//printf("return wstrlen:%d\n", wstrlen * -1);
			return (wstrlen * -1);
		}
		if (wstrlen + wcharlen > (int)n)
			return (wstrlen);
		wstrlen += wcharlen; 
		//printf("wcharlen:%d\twstrlen%d\n", wcharlen, wstrlen);
		++str;
	}
	return ((!wstrlen)) ? 1 : wstrlen; 
}
